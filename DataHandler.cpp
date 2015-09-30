//
// Created by Clancy Emanuel on 9/27/15.
//

#include "DataHandler.h"

DataHandler::DataHandler() {

}


void DataHandler::getAugmentedDataMatrix(std::string pathToData) {
    std::ifstream file;
    file.open(pathToData);
    std::string delimeter = ",";
    size_t pos = 0;
    std::string token;
    std::string currentLine;

    dataMatrix.resize(numberOfFeatures + 1, numberOfSamples);//+1 because we need the last variable to be the class
    Eigen::VectorXd temporaryDataVector(numberOfFeatures + 1);//see above comment for resizing data matrix

    std::getline(file, currentLine);//read in one line from the file containing the data
    int i = 0;
    while (!file.eof() && !file.fail() && (currentLine.size() > 2)) {// check if file is open and make if at eof
        int j = 0;
        while ((pos = currentLine.find(delimeter)) != std::string::npos && file) {//while we haven't reached endl
            token = currentLine.substr(0, pos);//take the next element
            temporaryDataVector(j) = std::stod(token);//and put it in a vector
            j++;//increment the counter
            currentLine.erase(0, pos + delimeter.length());//delete the element from the string (not the vector)
        }
        if (!classIndexIsFirst)temporaryDataVector(numberOfFeatures) = assignClassNumber(currentLine);

        dataMatrix.col(i) = temporaryDataVector;//put that feature vector in the data matrix
        std::getline(file, currentLine);//read in one line from the file containing the data
        i++;
    }
    //std::cout << dataMatrix << std::endl;//print the matrix for debugging and stuff

    file.close();//close the file once it's all done
}


void DataHandler::setNumberOfClasses(int theNumberOfClasses) {
    numberOfClasses = theNumberOfClasses;
}

void DataHandler::setNumberOfFeatures(int theNumberOfFeatures) {
    numberOfFeatures = theNumberOfFeatures;
}

void DataHandler::setNumberOfSamples(int theNumberOfSamples) {
    numberOfSamples = theNumberOfSamples;
}


void DataHandler::setParameters(int theNumberOfClasses, int theNumberOfFeatures, int theNumberOfSamples, std::string classIndex) {
    setNumberOfClasses(theNumberOfClasses);
    setNumberOfFeatures(theNumberOfFeatures);
    setNumberOfSamples(theNumberOfSamples);
    if(classIndex == "last") classIndexIsFirst = 0;
    else{classIndexIsFirst = 1;}
}

int DataHandler::assignClassNumber(std::string classValue) {
    //IRIS RULES
    if(classValue.compare("Iris-setosa")==0) return 0;
    else if(classValue.compare("Iris-versicolor")==0) return 1;
    else if(classValue.compare("Iris-virginica")==0)return 2;

    //To add another follow the same format and comment out any other data set rule.
    else{return -1;}
}

Eigen::MatrixXd* DataHandler::getDataMatrix() {
    return &dataMatrix;
}

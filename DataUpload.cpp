//
// Created by Clancy Emanuel on 9/27/15.
//

#include "DataUpload.h"

DataUploader::DataUploader() {

}


void DataUploader::uploadData(std::string pathToData) {
    std::ifstream file;
    file.open(pathToData);
    std::string delimeter = ",";
    size_t pos = 0;
    std::string token;
    std::string currentLine;

    std::cout<< "number of classes:"<<numberOfClasses<<std::endl<<"number of features:"<<numberOfFeatures<<std::endl<<
            "number of samples:"<<numberOfSamples<<std::endl;

    dataMatrix.resize(numberOfFeatures+1,numberOfSamples);//+1 because we need the last variable to be the class
    Eigen::VectorXd temporaryDataVector(numberOfFeatures+1);//see above comment for resizing data matrix
    if (file.is_open()) {
        std::getline(file,currentLine);
        int j = 0;
        while((pos = currentLine.find(delimeter)) != std::string::npos&&file){
            token = currentLine.substr(0,pos);
            temporaryDataVector(j) = std::stod(token);
            j++;
            currentLine.erase(0, pos + delimeter.length());
        }
        temporaryDataVector(j) = std::stod(token);
        std::cout<< temporaryDataVector<<std::endl;

        for(int i = 0;i<numberOfSamples;i++){
            dataMatrix.col(i) = temporaryDataVector;
        }

        std::cout << dataMatrix << std::endl;
    }
    file.close();
}


void DataUploader::setNumberOfClasses(int theNumberOfClasses) {
    numberOfClasses = theNumberOfClasses;
}

void DataUploader::setNumberOfFeatures(int theNumberOfFeatures) {
    numberOfFeatures = theNumberOfFeatures;
}

void DataUploader::setNumberOfSamples(int theNumberOfSamples) {
    numberOfSamples = theNumberOfSamples;
}


void DataUploader::setParameters(int theNumberOfClasses, int theNumberOfFeatures, int theNumberOfSamples) {
    setNumberOfClasses(theNumberOfClasses);
    setNumberOfFeatures(theNumberOfFeatures);
    setNumberOfSamples(theNumberOfSamples);
}

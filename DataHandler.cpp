//
// Created by Clancy Emanuel on 9/27/15.
//

#include "DataHandler.h"

DataHandler::DataHandler() {

}




void DataHandler::uploadData(std::string pathToData) {
    std::string pathToConfigFile;
    pathToConfigFile = pathToData;
    pathToConfigFile.insert(pathToConfigFile.length()-4,"Config");
    getConfigurationDetails(pathToConfigFile);//sets general parameters
    loadDataMatrix(pathToData);

}

Eigen::MatrixXd* DataHandler::getDataMatrix() {
    return &dataMatrix;
}

Eigen::MatrixXd DataHandler::loadDataMatrix(std::string pathToData) {
    std::ifstream file;
    file.open(pathToData);
    std::string delimeter = ",";
    size_t pos = 0;
    std::string token;
    std::string currentLine;

    augmentedDataMatrix.resize(numberOfFeatures+1,numberOfSamples);
    Eigen::VectorXd temporaryDataVector;
    temporaryDataVector.resize(numberOfFeatures+1);

    std::getline(file, currentLine);//read in one line from the file containing the data
    int i = 0;
    while (!file.eof() && !file.fail() && (currentLine.size() > 2)) {// check if file is open and make if at eof
        int j = 0;
        int classAssigned = 0;
        while ((pos = currentLine.find(delimeter)) != std::string::npos && file) {//while we haven't reached endl
            token = currentLine.substr(0, pos);//take the next element
            if(classIndexIsFirst&&classAssigned==0){
                temporaryDataVector(numberOfFeatures)=classes[token];
                classAssigned=1;
            }
            else {
                temporaryDataVector(j) = std::stod(token);
                j++;
            }
            currentLine.erase(0, pos + delimeter.length());//delete the element from the string
        }
        if(!classIndexIsFirst)temporaryDataVector(numberOfFeatures) = classes[currentLine];
        else{temporaryDataVector(j)=std::stod(currentLine);}

           // std::cout<<temporaryDataVector<<std::endl;

        augmentedDataMatrix.col(i) = temporaryDataVector;//put that feature vector in the data matrix
        std::getline(file, currentLine);//read in one line from the file containing the data
        i++;
    }
    //std::cout << augmentedDataMatrix.leftCols(210) << std::endl;//print the matrix for debugging and stuff
    dataMatrix = augmentedDataMatrix.topRows(numberOfFeatures);
    std::cout<<dataMatrix<<std::endl;
    file.close();//close the file once it's all done
}

void DataHandler::getConfigurationDetails(std::string pathToConfigFile) {
    std::cout<<pathToConfigFile<<std::endl;
    std::ifstream file;
    file.open(pathToConfigFile);
    std::string currentLine, previousLine;
    std::getline(file, currentLine);
    if(currentLine.compare("Class names:")==0) {
        std::getline(file,currentLine);
        int j = 1;
        while(currentLine.compare("stop here")!=0){
            if(currentLine.compare(previousLine)==0){
                std::cout<<"Infinite loop canceled in CLASS NAMES - use 'stop here' after every section.";
                break;
            }
            classes[currentLine]=j;
            j++;
            previousLine = currentLine;
            std::getline(file,currentLine);
        }
        std::getline(file,currentLine);
    }
    else{std::cout<<"Error retrieving class names. First line of configuration file should be 'Class names:'";}
    if(currentLine.compare("Number of features:")==0){
        std::getline(file,currentLine);
        while(currentLine.compare("stop here")!=0) {
            if(currentLine.compare(previousLine)==0){
                std::cout<<"Infinite loop canceled in NUMBER OF FEATURES - use 'stop here' after every section.";
                break;
            }
            numberOfFeatures = std::stod(currentLine);
            std::cout<<"Number of features = "<<numberOfFeatures<<std::endl;
            previousLine = currentLine;
            std::getline(file, currentLine);
        }
        std::getline(file,currentLine);
    }
    else{ std::cout<<"Error retrieving number of features. See config file example for help.";}
    if(currentLine.compare("Number of samples:")==0){
        std::getline(file,currentLine);
        while(currentLine.compare("stop here")!=0){
            if(currentLine.compare(previousLine)==0){
                std::cout<<"Infinite loop canceled in NUMBER OF SAMPLES - use 'stop here' after every section.";
                break;
            }
            numberOfSamples = std::stod(currentLine);
            std::cout<<"Number of samples = "<<numberOfSamples<<std::endl;
            previousLine = currentLine;
            std::getline(file,currentLine);
        }
        std::getline(file,currentLine);
    }
    else{ std::cout<<"Error retrieving number of samples. See config file example for help.";}
    if(currentLine.compare("Class index:")==0){
        std::getline(file,currentLine);
        if(currentLine.compare("first")==0) classIndexIsFirst = 1;
        else if(currentLine.compare("last")==0)classIndexIsFirst = 0;
        else if(currentLine.compare("unsupervised")==0)classIndexIsFirst=2;//indicates we don't have class names
        else{
            classIndexIsFirst = -1;
            std::cout<<"Please enter class index. See config file example for help.";
        }
        if(classIndexIsFirst != -1) {
            std::cout << "Class index = " << currentLine << std::endl;
            std::cout << "Successfully loaded configuration details."<<std::endl;
        }
    }
    else{ std::cout<<"Error retrieving class index. See config file example for help.";}
    file.close();
}
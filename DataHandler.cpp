//
// Created by Clancy Emanuel on 9/27/15.
//

#include "DataHandler.h"

DataHandler::DataHandler() {

}




void DataHandler::uploadData(std::string pathToData) {
    std::string pathToConfigFile;
    pathToConfigFile = pathToData;
    pathToConfigFile.insert(pathToConfigFile.length()-4,"Config");//make path to config file
    getConfigurationDetails(pathToConfigFile);//sets general parameters
    loadDataMatrix(pathToData);

}

Eigen::MatrixXd* DataHandler::getDataMatrix() {
    return &dataMatrix;
}



void DataHandler::loadDataMatrix(std::string pathToData) {
    std::ifstream file;
    file.open(pathToData);
    std::string delimeter = ",";
    size_t pos = 0;
    std::string token;
    std::string currentLine;

    augmentedDataMatrix.resize(numberOfSamples,numberOfFeatures+1);
    Eigen::VectorXd temporaryDataVector;
    temporaryDataVector.resize(numberOfFeatures+1);

    std::getline(file, currentLine);//read in one line of data (AKA one feature vector)
    int i = 0;
    while (!file.eof() && !file.fail() && (currentLine.size() > 2)) {// check if file is open and if at eof
        int j = 0;
        int classAssigned = 0;
        while ((pos = currentLine.find(delimeter)) != std::string::npos && file) {//while we haven't reached endl
            token = currentLine.substr(0, pos);//take the next element as indicated by the delimeter
            if(classIndexIsFirst&&classAssigned==0){
                temporaryDataVector(numberOfFeatures)=classes[token];//assign the extra vector element as the class
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
        augmentedDataMatrix.row(i) = temporaryDataVector;//put that feature vector in the data matrix
        std::getline(file, currentLine);//read in one line from the file containing the data
        i++;
    }
    dataMatrix = augmentedDataMatrix.leftCols(numberOfFeatures);
    classVector = augmentedDataMatrix.rightCols(1);

    file.close();//close the file once it's all done
}

void DataHandler::getConfigurationDetails(std::string pathToConfigFile) {
    std::cout<<pathToConfigFile<<std::endl;
    std::ifstream file;
    try {
        file.open(pathToConfigFile);
    }
    catch (int e)
    {
        std::cout<<"Cannot find config file in the same directory as data."<<std::endl;
    }
    std::string currentLine, previousLine;
    std::getline(file, currentLine);
    if(currentLine.compare("Class names:")==0) {//maps all of the class names to integers
        std::getline(file,currentLine);
        int j = 0;//class enumeration starts at 0
        while(currentLine.compare("stop here")!=0){
            if(currentLine.compare(previousLine)==0){
                std::cout<<"Infinite loop canceled in CLASS NAMES - use 'stop here' after every section.";
                break;
            }
            classes[currentLine]=j;//actual line that does the mapping
            j++;
            previousLine = currentLine;
            std::getline(file,currentLine);
        }
        numberOfClasses = j;// set numberOfClasses parameter
        std::getline(file,currentLine);
    }
    else{std::cout<<"Error retrieving class names. First line of configuration file should be 'Class names:'";}
    if(currentLine.compare("Number of features:")==0){//Read config file for how many features per vector
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
    if(currentLine.compare("Number of samples:")==0){//Read config file for how many samples in data set
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
    if(currentLine.compare("Class index:")==0){//Indicates whether the class assignment is first or last in each vector
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

void DataHandler::calculateClassMeans() {
    Eigen::MatrixXd zeroVector = Eigen::MatrixXd::Zero(1, numberOfFeatures);//initial mean vector
    meanMatrix.resize(numberOfClasses, numberOfFeatures);
    meanMatrix.setZero(numberOfClasses, numberOfFeatures);
    int classValue;
    std::vector<int>classCounter(numberOfClasses,0);
    for(int i = 0;i<numberOfSamples;i++) {
        classValue = augmentedDataMatrix(i, numberOfFeatures);//class value is stored in last row
        meanMatrix.row(classValue) += dataMatrix.row(i);
        classCounter[classValue]++;
    }

    for(int i = 0;i<numberOfClasses;i++){
        meanMatrix.row(i) /= classCounter[i];
    }
}

void DataHandler::calculateClassCovariances() {
    Eigen::MatrixXd copyOfDataMatrix;
    Eigen::MatrixXd x,mu,error, tempMatrix;
    int classValue;
    std::vector<int>classCounter(numberOfClasses,0);
    Eigen::MatrixXd zeroMatrix = Eigen::MatrixXd::Zero(numberOfFeatures,numberOfFeatures);//covariance matrix size

    vectorOfCovariances.resize(numberOfClasses,zeroMatrix);
    x.resize(1, numberOfFeatures);
    mu.resize(1, numberOfFeatures);
    error.resize(numberOfFeatures,1);


    copyOfDataMatrix.resize(numberOfSamples, numberOfFeatures);//copying to make sure original is preserved
    copyOfDataMatrix = dataMatrix;


    for(int i = 0;i<numberOfSamples;i++){
        classValue = augmentedDataMatrix(i, numberOfFeatures);//assigning double to int b/c class values are ints
        x = copyOfDataMatrix.row(i);
        mu = meanMatrix.row(classValue);
        error = (x-mu).transpose();// take transpose because x and mu are row vectors
        vectorOfCovariances[classValue] +=  error*error.transpose();//outer product (dyad)
        classCounter[classValue]++;
    }
    for(int i = 0;i<numberOfClasses;i++){
        vectorOfCovariances[i] /= (classCounter[i]-1);// -1 for unbiased estimator
    }
}

void DataHandler::calculateClassProbabilities() {
    int classValue;

    vectorOfClassProbabilities.resize(numberOfClasses);

    for(int i = 0;i<numberOfSamples;i++){
        classValue = classVector(i,0);
        vectorOfClassProbabilities[classValue]++;//tally the number of times a class occurs
    }
    for(int i = 0;i<numberOfClasses;i++){
        vectorOfClassProbabilities[i] /= numberOfSamples;//divide by the total number of samples
        std::cout<<"Class["<<i<<"] probability:"<<std::endl<<vectorOfClassProbabilities[i]<<std::endl;
    }

}

void DataHandler::calculateMLCovariance() {
    optimalMLCovariance = Eigen::MatrixXd::Zero(numberOfFeatures,numberOfFeatures);
    for(int i = 0;i<numberOfClasses;i++){
        optimalMLCovariance += vectorOfCovariances[i];
    }
    optimalMLCovariance /= (numberOfSamples-numberOfClasses);
}

int DataHandler::getNumberOfSamples() {
    return numberOfSamples;
}

int DataHandler::getNumberOfFeatures() {
    return numberOfFeatures;
}

int DataHandler::getNumberOfClasses() {
    return numberOfClasses;
}

Eigen::MatrixXd DataHandler::getMeanMatrix() {
    return meanMatrix;
}

std::vector<Eigen::MatrixXd> DataHandler::getVectorOfCovariances() {
    return vectorOfCovariances;
}

Eigen::MatrixXd DataHandler::getClassVector() {
    return classVector;
}

std::vector<double> DataHandler::getClassProbabilities() {
    return vectorOfClassProbabilities;
}

Eigen::MatrixXd DataHandler::getOptimalMLCovariance() {
    return optimalMLCovariance;
}

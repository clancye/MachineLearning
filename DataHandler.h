//
// Created by Clancy Emanuel on 9/27/15.
//

#ifndef MACHINE_LEARNING_DATAHANDLER_H
#define MACHINE_LEARNING_DATAHANDLER_H

#include <string>
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include "/usr/local/include/eigen3/Eigen/Eigen"


///Uploads data into vector format and indicates parameter values
class DataHandler {

    public:
    ///Class constructor
    DataHandler();
    ///uploads data into vector format
    void uploadData(std::string pathToData);
    void getConfigurationDetails(std::string pathToConfigFile);
    void calculateClassMeans();
    void calculateClassCovariances();
    void calculateClassProbabilities();
    Eigen::MatrixXd* getDataMatrix();
    Eigen::MatrixXd* getMeanMatrix();
    Eigen::MatrixXd* getClassVector();
    std::vector<Eigen::MatrixXd> getVectorOfCovariances();
    std::vector<double> getClassProbabilities();
    int getNumberOfClasses();
    int getNumberOfFeatures();
    int getNumberOfSamples();


    private:

    std::map<std::string,int> classes;
    std::vector<Eigen::MatrixXd> vectorOfCovariances;
    std::vector<double> vectorOfClassProbabilities;
    Eigen::MatrixXd dataMatrix, augmentedDataMatrix, meanMatrix, classVector;
    void loadDataMatrix(std::string pathToData);
    int numberOfFeatures,numberOfSamples, classIndexIsFirst, numberOfClasses;
};


#endif //MACHINE_LEARNING_DATAHANDLER_H

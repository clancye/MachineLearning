//
// Created by Clancy Emanuel on 9/27/15.
//

#ifndef MACHINE_LEARNING_DATAHANDLER_H
#define MACHINE_LEARNING_DATAHANDLER_H

#include <string>
#include<iostream>
#include<fstream>
#include<map>
#include "/usr/local/include/eigen3/Eigen/Eigen"

///Uploads data into vector format and indicates parameter values
class DataHandler {

    public:
    ///Class constructor
    DataHandler();
    ///uploads data into vector format
    void uploadData(std::string pathToData);
    void getConfigurationDetails(std::string pathToConfigFile);
    Eigen::MatrixXd* getDataMatrix();


    private:

    std::map<std::string,int> classes;
    Eigen::MatrixXd dataMatrix;
    Eigen::MatrixXd loadDataMatrix(std::string pathToData);
    int numberOfFeatures,numberOfSamples, classIndexIsFirst;
};


#endif //MACHINE_LEARNING_DATAHANDLER_H

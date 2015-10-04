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
#include <eigen3/Eigen/Eigen>


///Uploads data into vector format and indicates parameter values
class DataHandler {

    public:
    ///Class constructor
    DataHandler();
    ///uploads data into vector format
    void uploadData(std::string pathToData);
    void getConfigurationDetails(std::string pathToConfigFile);
    ///Calculates the mean of the vectors in each class
    void calculateClassMeans();
    ///Calculates the covariance of each class
    void calculateClassCovariances();
    ///Calculates the probability of each class
    void calculateClassProbabilities();
    ///Calculates the optimal ML estimate of covariance over all classes
    void calculateMLCovariance();
    ///Returns the address to dataMatrix
    Eigen::MatrixXd* getDataMatrix();
    ///Returns the address to meanMatrix
    Eigen::MatrixXd* getMeanMatrix();
    ///Returns address to classVector
    Eigen::MatrixXd* getClassVector();
    ///Returns address to optimalMLCovariance
    Eigen::MatrixXd* getOptimalMLCovariance();
    ///Returns vector containing all the covariance matrices
    std::vector<Eigen::MatrixXd> getVectorOfCovariances();
    ///Returns the vector containing the probabilities of each class
    std::vector<double> getClassProbabilities();
    ///Returns the number of classes
    int getNumberOfClasses();
    ///Returns the number of features
    int getNumberOfFeatures();
    ///Returns the number of samples
    int getNumberOfSamples();


    private:

    std::map<std::string,int> classes;
    std::vector<Eigen::MatrixXd> vectorOfCovariances;
    std::vector<double> vectorOfClassProbabilities;
    Eigen::MatrixXd dataMatrix, augmentedDataMatrix, meanMatrix, classVector, optimalMLCovariance;
    void loadDataMatrix(std::string pathToData);
    int numberOfFeatures,numberOfSamples, classIndexIsFirst, numberOfClasses;
};


#endif //MACHINE_LEARNING_DATAHANDLER_H

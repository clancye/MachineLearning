//
// Created by Clancy Emanuel on 9/27/15.
//

#ifndef MACHINE_LEARNING_DATAHANDLER_H
#define MACHINE_LEARNING_DATAHANDLER_H

#include <string>
#include<iostream>
#include<fstream>
#include "/usr/local/include/eigen3/Eigen/Eigen"

///Uploads data into vector format and indicates parameter values
class DataHandler {

    public:
    ///Class constructor
    DataHandler();
    ///uploads data into vector format
    void getAugmentedDataMatrix(std::string pathToData);
    void getConfigurationDetails(std::string pathToConfigFile);
    Eigen::MatrixXd* getDataMatrix();

    ///Sets the number of classes
    void setNumberOfClasses(int theNumberOfClasses);
    ///Sets the number of features (i.e. the length of a feature vector)
    void setNumberOfFeatures(int theNumberOfFeatures);
    ///Sets the number of samples (i.e. the number of feature vectors)
    void setNumberOfSamples(int theNumberOfSamples);

    ///Calls the setters in batch
    void setParameters(int theNumberOfClasses, int theNumberOfFeatures, int theNumberOfSamples, std::string classIndex);

    private:
    ///Takes the class value as given in the data and converts to a number in case it is originally a string
    int assignClassNumber(std::string classValue);//returns an int based on class rule

    Eigen::MatrixXd dataMatrix;
    int numberOfClasses,numberOfFeatures,numberOfSamples, classIndexIsFirst;//if classIndex == last, classIndexBinary = 1

};


#endif //MACHINE_LEARNING_DATAHANDLER_H

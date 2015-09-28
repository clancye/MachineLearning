//
// Created by Clancy Emanuel on 9/27/15.
//

#ifndef MACHINE_LEARNING_DATAUPLOAD_H
#define MACHINE_LEARNING_DATAUPLOAD_H

#include <string>
#include<iostream>
#include<fstream>
#include "/usr/local/include/eigen3/Eigen/Eigen"

///Uploads data into vector format and indicates parameter values
class DataUploader {

    public:
    ///Class constructor
    DataUploader();
    ///uploads data into vector format
    void uploadData(std::string pathToData);

    ///Sets the number of classes
    void setNumberOfClasses(int theNumberOfClasses);
    ///Sets the number of features (i.e. the length of a feature vector)
    void setNumberOfFeatures(int theNumberOfFeatures);
    ///Sets the number of samples (i.e. the number of feature vectors)
    void setNumberOfSamples(int theNumberOfSamples);

    ///Calls the setters in batch
    void setParameters(int theNumberOfClasses, int theNumberOfFeatures, int theNumberOfSamples);

    private:

    Eigen::MatrixXd dataMatrix;
    int numberOfClasses,numberOfFeatures,numberOfSamples;
};


#endif //MACHINE_LEARNING_DATAUPLOAD_H

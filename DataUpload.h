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

    DataUploader();

    ///uploads data into vector format
    void uploadData(int numberOfClasses, int numberOfFeatures, std::string pathToData);

};


#endif //MACHINE_LEARNING_DATAUPLOAD_H

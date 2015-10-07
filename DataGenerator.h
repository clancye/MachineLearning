//
// Created by Clancy Emanuel on 10/5/15.
//

#ifndef MACHINE_LEARNING_DATAGENERATOR_H
#define MACHINE_LEARNING_DATAGENERATOR_H

#include <eigen3/Eigen/Eigen>
#include <random>
#include <iostream>

class DataGenerator {

    public:
    DataGenerator();

    double randomGaussianNumber(double aMean, double aVariance);
    Eigen::MatrixXd randomGaussianVector(Eigen::MatrixXd aMeanVector, Eigen::MatrixXd aCovariance);
    Eigen::MatrixXd randomGaussianVectors(int aNumberOfVectors, Eigen::MatrixXd aMeanVector, Eigen::MatrixXd aCovariance);

};


#endif //MACHINE_LEARNING_DATAGENERATOR_H

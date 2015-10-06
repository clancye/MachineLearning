//
// Created by Clancy Emanuel on 10/5/15.
//

#include "DataGenerator.h"

DataGenerator::DataGenerator() {

}

double DataGenerator::randomGaussianNumber(double aMean, double aVariance) {
    std::random_device randomDevice{};//create seed generator
    std::mt19937 engine{randomDevice()};//initialize engine
    std::normal_distribution<double> normalDistribution(aMean, aVariance);//make a distribution

    double randomNumber = normalDistribution(engine);

    return randomNumber;
}

double DataGenerator::randomGaussianVector(Eigen::MatrixXd aMeanVector, Eigen::MatrixXd aCovariance) {
    return 0;
}

Eigen::MatrixXd DataGenerator::randomGaussianVectors(int aNumberOfVectors, Eigen::MatrixXd aMeanVector,
                                                     Eigen::MatrixXd aCovariance) {
    return aMeanVector;
}

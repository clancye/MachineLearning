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

Eigen::MatrixXd DataGenerator::randomGaussianVector(Eigen::MatrixXd aMeanVector, Eigen::MatrixXd aCovariance) {
    Eigen::EigenSolver<Eigen::MatrixXd> eigenSolver;
    Eigen::MatrixXcd Q, sqrtLambda, eigenValuesVector, matrixCoefficient;
    Eigen::MatrixXd aRandomVector, mu, r,y, realMatrixCoefficient;
    int vectorSize, rows, cols;

    mu = aMeanVector;
    vectorSize = mu.rows();
    r.resize(vectorSize,1);
    y.resize(vectorSize,1);

    eigenSolver.compute(aCovariance, true);
    Q = eigenSolver.eigenvectors();
    eigenValuesVector = eigenSolver.eigenvalues();
    eigenValuesVector = eigenValuesVector.array().sqrt();
    sqrtLambda = eigenValuesVector.asDiagonal();

    for(int i = 0;i<vectorSize;i++){
        r(i,0) =  randomGaussianNumber(0,1);
    }

    matrixCoefficient = Q*sqrtLambda;
    rows = matrixCoefficient.rows();
    cols = matrixCoefficient.cols();
    realMatrixCoefficient.resize(rows,cols);
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            realMatrixCoefficient(i,j) = std::real(matrixCoefficient(i,j));
        }
    }
    y = realMatrixCoefficient*r+mu;


    return y;
}

Eigen::MatrixXd DataGenerator::randomGaussianVectors(int aNumberOfVectors, Eigen::MatrixXd aMeanVector,
                                                     Eigen::MatrixXd aCovariance) {
    return aMeanVector;
}

double DataGenerator::randomUniformNumber(double min, double max) {
    std::random_device randomDevice{};
    std::mt19937 engine{randomDevice()};
    std::uniform_real_distribution<double> uniformRealDistribution(min,max);

    return uniformRealDistribution(engine);
}

Eigen::MatrixXd DataGenerator::randomUniformVector(int aSize, double aMin, double aMax) {
    const int size = aSize;
    Eigen::MatrixXd randomVector;

    randomVector.resize(aSize,1);

    for(int i = 0;i<size;i++){
        randomVector(i,0) = randomUniformNumber(aMin,aMax);
    }
    return randomVector;
}

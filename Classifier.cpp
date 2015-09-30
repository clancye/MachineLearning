//
// Created by Clancy Emanuel on 9/29/15.
//

#include "Classifier.h"

Classifier::Classifier() {

}

void Classifier::useLDA(Eigen::MatrixXd *dataMatrix) {
    //Calculate mean and vector for each class
    findClassMeans(dataMatrix);
    //Calculate covariance of each class
    //Using these calculate the discriminants
}

Eigen::MatrixXd Classifier::findClassMeans(Eigen::MatrixXd *dataMatrix) {
    int numberOfFeatures = dataMatrix->rows() - 1;//-1 because the last element is the class assignment
    int numberOfSamples = dataMatrix->cols();

    Eigen::MatrixXd dataWithoutClasses(numberOfFeatures, numberOfSamples);
    dataWithoutClasses = dataMatrix->topRows(numberOfFeatures);
    std::cout<<"data w/out class!"<<std::endl<<dataWithoutClasses<<std::endl;

    for(int i = 0;i<numberOfSamples;i++){

    }

    return *dataMatrix;
}

//
// Created by Clancy Emanuel on 9/29/15.
//

#ifndef MACHINE_LEARNING_CLASSIFIER_H
#define MACHINE_LEARNING_CLASSIFIER_H

#include <iostream>
#include "/usr/local/include/eigen3/Eigen/Eigen"
#include "DataHandler.h"
#include <cmath>

class Classifier {

    public:

    Classifier();

    void LDA();
    void setDataHandler(DataHandler *dataHandler);


    private:
    DataHandler *dataHandler;

    int calculateDiscriminant(Eigen::MatrixXd someX, Eigen::MatrixXd someMu, Eigen::MatrixXd someSigma, int aClassProb );

};


#endif //MACHINE_LEARNING_CLASSIFIER_H

//
// Created by Clancy Emanuel on 9/29/15.
//

#ifndef MACHINE_LEARNING_CLASSIFIER_H
#define MACHINE_LEARNING_CLASSIFIER_H

#include <iostream>
#include <eigen3/Eigen/Eigen>
#include "DataHandler.h"
#include <cmath>
#include <algorithm>
#include <gnuplot-iostream/gnuplot-iostream.h>

class Classifier {

    public:

    Classifier();

    void DiscriminantAnalysis(int aQDA);
    void setDataHandler(DataHandler *dataHandler);


    private:
    DataHandler *dataHandler;

    double calculateDiscriminant(Eigen::MatrixXd someX, Eigen::MatrixXd someMu, Eigen::MatrixXd someSigma, double aClassProb, int QDA);

};


#endif //MACHINE_LEARNING_CLASSIFIER_H

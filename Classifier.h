//
// Created by Clancy Emanuel on 9/29/15.
//

#ifndef MACHINE_LEARNING_CLASSIFIER_H
#define MACHINE_LEARNING_CLASSIFIER_H

#include <iostream>
#include "/usr/local/include/eigen3/Eigen/Eigen"

class Classifier {

    public:

    Classifier();

    void useLDA(Eigen::MatrixXd *dataMatrix);


    private:
    Eigen::MatrixXd findClassMeans(Eigen::MatrixXd *dataMatrix);

};


#endif //MACHINE_LEARNING_CLASSIFIER_H

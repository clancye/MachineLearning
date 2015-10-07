//
// Created by Clancy Emanuel on 10/7/15.
//

#ifndef MACHINE_LEARNING_BETADISTRIBUTION_H
#define MACHINE_LEARNING_BETADISTRIBUTION_H

#include<vector>
#include <cmath>
class BetaDistribution {

    public:
    ///Constructor for BetaDistribution
    BetaDistribution();

    ///Calculates the hyperparameters based on user input for mean and variance of Beta Distribution.
    void calculateHyperParameters(double aMean, double aVariance);
    ///Returns the hyper parameters. Must calculate them first.
    std::vector<double> getHyperParameters();

    private:
    std::vector<double> hyperParameters;
    double a,b;

};


#endif //MACHINE_LEARNING_BETADISTRIBUTION_H

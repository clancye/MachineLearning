//
// Created by Clancy Emanuel on 10/7/15.
//

#include "BetaDistribution.h"

BetaDistribution::BetaDistribution() {

}

void BetaDistribution::calculateHyperParameters(double aMean, double aVariance) {
    double numerator, denominator, m,v, X;
    m = aMean;
    v = aVariance;
    X = (1-m)/m;

    numerator = ((X/v)-(1+2*X+pow(X,2)));
    denominator = 1+3*X+3*pow(X,2)+pow(X,3);

    a = numerator/denominator;
    b = X*a;

    hyperParameters.push_back(a);
    hyperParameters.push_back(b);
}

std::vector<double> BetaDistribution::getHyperParameters() {
    return hyperParameters;
}

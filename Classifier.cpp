//
// Created by Clancy Emanuel on 9/29/15.
//

#include "Classifier.h"

Classifier::Classifier() {

}

void Classifier::LDA() {
    int classAssignment,g;
    Eigen::MatrixXd *dataMatrix, *meanMatrix, *classVector;
    dataMatrix=dataHandler->getDataMatrix();
    std::vector<Eigen::MatrixXd> vectorOfCovariances;
    std::vector<double> classProbabilities;

    classAssignment = 0;
    meanMatrix = dataHandler->getMeanMatrix();
    vectorOfCovariances = dataHandler->getVectorOfCovariances();
    classVector = dataHandler->getClassVector();
    classProbabilities = dataHandler->getClassProbabilities();
    for(int i = 0;i<dataHandler->getNumberOfSamples();i++){//iterate through all samples
        for (int j = 0;j < classProbabilities.size();j++) {//calculate the discriminant for every class and take max
            g = calculateDiscriminant(dataMatrix->col(i), meanMatrix->col(j),
                                      vectorOfCovariances[j], classProbabilities[j]);
            std::cout<<"Discriminant for class["<<j<<"] = "<<g<<std::endl;
        }
    }
}


void Classifier::setDataHandler(DataHandler *aDataHandler) {
    dataHandler = aDataHandler;
}

int Classifier::calculateDiscriminant(Eigen::MatrixXd someX, Eigen::MatrixXd someMu, Eigen::MatrixXd someSigma, int aClassProb ) {
    double g, P, SigmaDet;
    Eigen::MatrixXd x,xT,mu,muT,Sigma, SigmaInv;
    x = someX;
    xT = x.transpose();
    mu = someMu;
    muT = mu.transpose();
    Sigma = someSigma;
    SigmaInv = Sigma.inverse();
    SigmaDet = Sigma.determinant();
    P = aClassProb;

   // g = -.5*xT*SigmaInv*x + muT*SigmaInv*x - (.5*muT*SigmaInv*mu + .5*log(SigmaDet) - log(P));

    return g;

}

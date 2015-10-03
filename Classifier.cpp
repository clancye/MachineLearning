//
// Created by Clancy Emanuel on 9/29/15.
//

#include "Classifier.h"

Classifier::Classifier() {

}

void Classifier::LDA() {
    int classAssignment;
    double g;
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
            g = calculateDiscriminant(dataMatrix->col(i), meanMatrix->col(j), vectorOfCovariances[0], classProbabilities[j]);
            std::cout<<i<<"  Discriminant for class["<<j<<"] = "<<g<<std::endl;
        }
    }
}


void Classifier::setDataHandler(DataHandler *aDataHandler) {
    dataHandler = aDataHandler;
}

double Classifier::calculateDiscriminant(Eigen::MatrixXd someX, Eigen::MatrixXd someMu, Eigen::MatrixXd someSigma, double aClassProb ) {
    int numberOfFeatures;
    double g, P, SigmaDet;
    Eigen::MatrixXd x,xT,mu,muT,Sigma, SigmaInv;
    numberOfFeatures = dataHandler->getNumberOfFeatures();

    x.resize(numberOfFeatures,1);
    xT.resize(1,numberOfFeatures);
    mu.resize(numberOfFeatures,1);
    muT.resize(1,numberOfFeatures);
    Sigma.resize(numberOfFeatures,numberOfFeatures);
    SigmaInv.resize(numberOfFeatures, numberOfFeatures);

    x = someX;
    xT = x.transpose();
    mu = someMu;
    muT = mu.transpose();
    Sigma = someSigma;
    SigmaInv = Sigma.inverse();
    SigmaDet = Sigma.determinant();
    P = aClassProb;

    //QDA
    //g = -.5*(xT*SigmaInv*x)(0) + (muT*SigmaInv*x)(0) + .5*(muT*SigmaInv*mu)(0) - .5*log(SigmaDet) + log(P);

    //LDA
    g =  (muT*SigmaInv*x)(0) - .5*(muT*SigmaInv*mu)(0) + log(P);//zero in parentheses are for accessing eigen matrix

    return g;

}

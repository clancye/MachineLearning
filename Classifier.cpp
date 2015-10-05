//
// Created by Clancy Emanuel on 9/29/15.
//

#include "Classifier.h"

Classifier::Classifier() {

}

void Classifier::LDA() {
    int classAssignment, numberOfCorrectAssignments, numberOfSamples, numberOfFeatures, numberOfClasses;
    double g, gmax;
    Eigen::MatrixXd *dataMatrix, *meanMatrix, *classVector, *optimalMLCovariance;
    dataMatrix=dataHandler->getDataMatrix();
    std::vector<Eigen::MatrixXd> vectorOfCovariances;
    std::vector<double> classProbabilities;

    numberOfSamples = dataHandler->getNumberOfSamples();
    numberOfFeatures = dataHandler->getNumberOfFeatures();
    numberOfClasses = dataHandler->getNumberOfClasses();
    numberOfCorrectAssignments = 0;
    classAssignment = 0;
    gmax = -9999999;//brute force, but works for now
    meanMatrix = dataHandler->getMeanMatrix();
    vectorOfCovariances = dataHandler->getVectorOfCovariances();//USE THIS FOR QDA
    classVector = dataHandler->getClassVector();
    classProbabilities = dataHandler->getClassProbabilities();
    optimalMLCovariance = dataHandler->getOptimalMLCovariance();
    for(int i = 0;i<numberOfSamples;i++){//iterate through all samples
        for (int j = 0;j < numberOfClasses;j++) {//calculate the discriminant for every class and take max
            g = calculateDiscriminant(dataMatrix->row(i), meanMatrix->row(j), vectorOfCovariances[j], classProbabilities[j]);
            if(g>gmax)
            {
                gmax = g;
                classAssignment = j;
            }
        }
        gmax = 0;
        if(classAssignment == (classVector->row(i))(0)) numberOfCorrectAssignments++;
    }
    double percentageCorrect = (1.0*numberOfCorrectAssignments)/(1.0*numberOfSamples);//multiply by 1.0 to get doubles
    std::cout<<"Percentage correct = "<< percentageCorrect<<std::endl;
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

    x = someX.transpose();//this transpose is to keep consistency while using the statistical equations
    xT = someX;
    mu = someMu.transpose();
    muT = someMu;
    Sigma = someSigma;
    SigmaInv = Sigma.inverse();
    SigmaDet = Sigma.determinant();
    P = aClassProb;

    //QDA - zero in parentheses are for accessing eigen matrix
    g = -.5*(xT*SigmaInv*x)(0) + (muT*SigmaInv*x)(0) - .5*(muT*SigmaInv*mu)(0) - .5*log(SigmaDet) + log(P);

    //LDA - zero in parentheses are for accessing eigen matrix
    //g =  (muT*SigmaInv*x)(0) - .5*(muT*SigmaInv*mu)(0) + log(P);

    return g;

}

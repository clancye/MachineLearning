#include <iostream>
#include "DataHandler.h"
#include "Classifier.h"
#include "DataGenerator.h"
#include "Histogram.h"
#include "Statistics/BetaDistribution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataHandler dataHandler;
    Classifier classifier;
    DataGenerator dataGenerator;
    Histogram histogram;
    BetaDistribution betaDistribution;
    Eigen::MatrixXd *dataMatrix;

    dataHandler.uploadData("/Users/clancyemanuel/Dropbox/UConn/semesters/semester_9/Neural Networks/Homework/Homework 2/iris.txt");
    dataHandler.calculateClassMeans();
    dataHandler.calculateClassCovariances();
    dataHandler.calculateClassProbabilities();
    dataHandler.calculateMLCovariance();
    classifier.setDataHandler(&dataHandler);
    classifier.DiscriminantAnalysis(0);

    betaDistribution.calculateHyperParameters(.7,.04);
    std::vector<double> params = betaDistribution.getHyperParameters();

    std::cout<<"a = "<<params[0]<<std::endl<<"b = "<<params[1]<<std::endl;


/*
    Eigen::MatrixXd aMean1, aMean2, randomVector;
    Eigen::Matrix2d aCovarianceMatrix;

    aCovarianceMatrix<< 1,.25,
            .25,1;
    aMean1.resize(2,1);
    aMean2.resize(2,1);
    aMean1<<0,0;
    aMean2<<2,2;
    std::ofstream file1, file2;
    file1.open("gaussianExample1.txt");
    file2.open("gaussianExample2.txt");
    for(int i = 0;i<500;i++) {
        randomVector = dataGenerator.randomGaussianVector(aMean1, aCovarianceMatrix);
        file1<<randomVector.transpose()<<std::endl;
        randomVector = dataGenerator.randomGaussianVector(aMean2, aCovarianceMatrix);
        file2<<randomVector.transpose()<<std::endl;
    }
    file1.close();
    file2.close();*/
    //randomVector = dataGenerator.randomGaussianVector(aMean, aCovarianceMatrix);
   // std::cout<<"random vector = "<<std::endl<<randomVector<<std::endl;
    //histogram.createHistogram(randomNumbers,0.05, "gaussianExample.txt");

    return 0;
}
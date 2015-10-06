#include <iostream>
#include "DataHandler.h"
#include "Classifier.h"
#include "DataGenerator.h"
#include "Histogram.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataHandler dataHandler;
    Classifier classifier;
    DataGenerator dataGenerator;
    Histogram histogram;
    Eigen::MatrixXd *dataMatrix;

    dataHandler.uploadData("/Users/clancyemanuel/Dropbox/UConn/semesters/semester_9/Neural Networks/Homework/Homework 2/iris.txt");
    dataHandler.calculateClassMeans();
    dataHandler.calculateClassCovariances();
    dataHandler.calculateClassProbabilities();
    dataHandler.calculateMLCovariance();
    classifier.setDataHandler(&dataHandler);
    classifier.LDA();



    std::vector<double> randomNumbers;

    for(int i = 0;i<2000;i++) {
        double randNumb = dataGenerator.randomGaussianNumber(0, 1);
        randomNumbers.push_back(randNumb);
    }

    histogram.createHistogram(randomNumbers,0.05, "gaussianExample.txt");




    return 0;
}
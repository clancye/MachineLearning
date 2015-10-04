#include <iostream>
#include "DataHandler.h"
#include "Classifier.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataHandler dataHandler;
    Classifier classifier;
    Eigen::MatrixXd *dataMatrix;

    dataHandler.uploadData("/Users/clancyemanuel/Dropbox/UConn/semesters/semester_9/Neural Networks/Homework/Homework 2/iris.txt");
    dataHandler.calculateClassMeans();
    dataHandler.calculateClassCovariances();
    dataHandler.calculateClassProbabilities();
    dataHandler.calculateMLCovariance();
    classifier.setDataHandler(&dataHandler);
    classifier.LDA();



    return 0;
}
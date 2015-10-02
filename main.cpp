#include <iostream>
#include "DataHandler.h"
#include "Classifier.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataHandler dataHandler;
    Classifier classifier;
    Eigen::MatrixXd *dataMatrix;

    dataHandler.uploadData("/Users/clancyemanuel/Dropbox/UConn/semesters/semester_9/Neural Networks/Homework/Homework 2/wine.txt");
    dataHandler.calculateClassMeans();
    dataHandler.calculateClassCovariances();
    dataHandler.calculateClassProbabilities();
    classifier.setDataHandler(&dataHandler);
    classifier.LDA();



    return 0;
}
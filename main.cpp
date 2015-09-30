#include <iostream>
#include "DataHandler.h"
#include "Classifier.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataHandler dataHandler;
    Classifier classifier;


    dataHandler.uploadData("/Users/clancyemanuel/Dropbox/UConn/semesters/semester_9/Neural Networks/Homework/Homework 2/iris.txt");

 //   Eigen::MatrixXd *dataMatrix;
 //   dataMatrix = uploader.getDataMatrix();

   // classifier.useLDA(dataMatrix);



    return 0;
}
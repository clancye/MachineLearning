#include <iostream>
#include "DataHandler.h"
#include "Classifier.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataHandler dataHandler;
    Classifier classifier;
    int numberOfClasses,numberOfFeatures,numberOfSamples;
    std::string classIndex;
    numberOfClasses = 3;
    numberOfFeatures = 4;
    numberOfSamples = 150;
    classIndex = "last";//tells program whether the data lists the feature vector's class first or last.


   // uploader.setParameters(numberOfClasses, numberOfFeatures, numberOfSamples, classIndex);
   // uploader.uploadData("/Users/clancyemanuel/Desktop/iris.txt");

 //   Eigen::MatrixXd *dataMatrix;
 //   dataMatrix = uploader.getDataMatrix();

   // classifier.useLDA(dataMatrix);



    return 0;
}
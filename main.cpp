#include <iostream>
#include "DataUpload.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    DataUploader uploader;
    int numberOfClasses,numberOfFeatures,numberOfSamples;
    numberOfClasses = 3;
    numberOfFeatures = 4;
    numberOfSamples = 27;

    uploader.setParameters(numberOfClasses, numberOfFeatures, numberOfSamples);
    uploader.uploadData("/Users/clancyemanuel/Desktop/iris.txt");

    return 0;
}
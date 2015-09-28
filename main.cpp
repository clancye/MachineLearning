#include <iostream>
#include "DataUpload.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    DataUploader uploader;

    uploader.uploadData(1,2,"/Users/clancyemanuel/Desktop/iris.txt");

    return 0;
}
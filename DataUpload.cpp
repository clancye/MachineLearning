//
// Created by Clancy Emanuel on 9/27/15.
//

#include "DataUpload.h"

DataUploader::DataUploader() {

}

void DataUploader::uploadData(int numberOfClasses, int numberOfFeatures, std::string pathToData) {
    std::ifstream file;
    file.open(pathToData);
    std::string delimeter = ",";
    size_t pos = 0;
    std::string token;
    std::string currentLine;

    std::cout<<"here"<<std::endl;
    if (file.is_open()) {
        std::getline(file,currentLine);
        while((pos = currentLine.find(delimeter)) != std::string::npos){
            token = currentLine.substr(0,pos);
            std::cout<<token<<std::endl;
            currentLine.erase(0, pos + delimeter.length());
        }
        std::cout<<currentLine<<std::endl;
    }
    file.close();
}





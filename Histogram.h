//
// Created by Clancy Emanuel on 10/5/15.
//

#ifndef MACHINE_LEARNING_HISTOGRAM_H
#define MACHINE_LEARNING_HISTOGRAM_H

#include <vector>
#include <string>
#include <fstream>

class Histogram {

    public:
    ///Generates a histogram object
    Histogram();
    ///Detects min and max of data and creates a histogram based on bucketSize
    void createHistogram(std::vector<double> someData, double aBinSize, std::string aFileName);

    private:
    std::fstream file;
    void writeToFile(std::vector<int> someBinNumbers, double min, double aBinSize, std::string aFileName);

};


#endif //MACHINE_LEARNING_HISTOGRAM_H

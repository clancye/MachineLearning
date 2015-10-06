//
// Created by Clancy Emanuel on 10/5/15.
//

#include <math.h>
#include "Histogram.h"

Histogram::Histogram() {

}

void Histogram::createHistogram(std::vector<double> someData, double aBinSize, std::string aFileName) {
    int numberOfSamples, bin, numberOfBins;
    double binSize, rangeSize, min, max, tempData;
    std::vector<int> binNumbers;
    std::vector<double> data;

    data = someData;

    max = *std::max_element(data.begin(), data.end());
    min = *std::min_element(data.begin(), data.end());


    numberOfSamples = data.size();
    binSize = aBinSize;
    rangeSize = max - min;
    numberOfBins = ceil(rangeSize/binSize);
    binNumbers.resize(numberOfBins);

    for(int i = 0;i<numberOfSamples;i++){
        tempData = data[i] - min;
        bin = (int)floor(tempData/binSize);
        binNumbers[bin]++;
    }

    writeToFile(binNumbers, min, binSize, aFileName);
}

void Histogram::writeToFile(std::vector<int> someBinNumbers, double min, double aBinSize, std::string aFileName) {
    int numberOfBins, offset;
    std::ofstream file;
    std::vector<int> binNumbers;

    binNumbers = someBinNumbers;
    numberOfBins = binNumbers.size();
    offset = floor(min/aBinSize);

    file.open(aFileName);

    for(int i = 0; i<numberOfBins; i++){
        file<<i+offset<<" "<<binNumbers[i]<<std::endl;
    }
    file.close();
}

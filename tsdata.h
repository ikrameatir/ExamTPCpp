#ifndef TSDATA_H
#define TSDATA_H

#include <iostream>
#include <vector>
#include <cmath>

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;
    void normalize(std::vector<double>& series) ;
    double calculateMean(const std::vector<double>& series) ;
    double calculateStdDev(const std::vector<double>& series) ;
    
public:
    TimeSeriesDataset() : znormalize(false), isTrain(true), maxLength(0), numberOfSamples(0) {}

    TimeSeriesDataset(bool znormalize, bool isTrain)
        : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

    void addTimeSeries(const std::vector<double>& series, int label = -1);


    static double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) ;

    double calculateDTWDistance(size_t index1, size_t index2) const ;

    double calculateNormalizedEditDistance(size_t index1, size_t index2) const ;

    void displayDataset() ;
};

#endif 

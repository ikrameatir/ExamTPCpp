#ifndef KNN_H
#define KNN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "tsdata.h" 


class KNN {

private:
    int k; 
    std::string similarityMeasure; 
    TimeSeriesDataset trainingSet; 

    double calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const ;
    
public:
    KNN(int k, const std::string& similarityMeasure)
        : k(k), similarityMeasure(similarityMeasure) {}

    double evaluate(const TimeSeriesDataset& trainSet, const TimeSeriesDataset& testSet, const std::vector<int>& groundTruth) const;


    int predict(const std::vector<double>& querySeries) const ;

    
    void setTrainingSet(const TimeSeriesDataset& trainingData) ;

};

#endif 

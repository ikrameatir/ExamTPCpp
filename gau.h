#ifndef GAU_H
#define GAU_H

#include "TimeSeriesGenerator.h"
#include <cmath>
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;   
    double stddev; 
    
public:
    GaussianGenerator() : TimeSeriesGenerator(), mean(0.0), stddev(1.0) {}

    GaussianGenerator(int seed, double mean, double stddev)
        : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {}

    std::vector<double> generateTimeSeries(int size) override ;


};

#endif

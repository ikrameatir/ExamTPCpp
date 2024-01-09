#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

#include <iostream>
#include <vector>
#include <cstdlib>

class TimeSeriesGenerator {
protected:
    int seed;
    
public:
    TimeSeriesGenerator() : seed(0) {}

    TimeSeriesGenerator(int seed) : seed(seed) {}

    virtual std::vector<double> generateTimeSeries(int size) = 0;

    static void printTimeSeries(const std::vector<double>& series) {
        std::cout << "Time Series: ";
        for (double value : series) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } 
};

#endif

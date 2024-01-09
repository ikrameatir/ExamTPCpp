#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "TimeSeriesGenerator.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator() : TimeSeriesGenerator() {
        srand(static_cast<unsigned>(time(nullptr)));
    }
    StepGenerator(int seed) : TimeSeriesGenerator(seed) {
        srand(seed);
    }

    std::vector<double> generateTimeSeries(int size) override {
        std::vector<double> series;
        series.reserve(size);
        series.push_back(0);

        for (int i = 1; i < size; ++i) {
            if (rand() % 2 == 0) {
                series.push_back(series[i - 1]);
            } else {
                series.push_back(rand() % 101);
            }
        }

        return series;
    }
};

#endif 

#ifndef KNNDOUBLE_H
#define KNNDOUBLE_H

#include "KNN.h"
#include <cmath> 

class KNNDouble : public KNN<std::pair<double, double>> {
public:
    using KNN<std::pair<double, double>>::KNN;

    double similarityMeasure(std::pair<double, double> &a, std::pair<double, double> &b) const override {
        return std::sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
    }
};

#endif


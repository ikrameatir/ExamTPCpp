#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "tsdata.h" 
#include "knn.h"

class KNN {

private:
    int k;  
    std::string similarityMeasure; 
    TimeSeriesDataset trainingSet; 

    double calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const {
        if (similarityMeasure == "euclidean") {
            return TimeSeriesDataset::euclideanDistance(series1, series2);
        }

        throw std::invalid_argument("Unknown similarity measure");
    }
    
public:
    KNN(int k, const std::string& similarityMeasure)
        : k(k), similarityMeasure(similarityMeasure) {}

    double KNN::evaluate(const TimeSeriesDataset& trainSet, const TimeSeriesDataset& testSet, const std::vector<int>& groundTruth) const {
    if (trainSet.getNumberOfSamples() != groundTruth.size()) {
        throw std::invalid_argument("Mismatched sizes between train set and ground truth.");
    }

    size_t totalSamples = testSet.getNumberOfSamples();
    size_t correctPredictions = 0;

    for (size_t i = 0; i < totalSamples; ++i) {
        int trueLabel = groundTruth[i];
        int predictedLabel = predict(testSet.getData(i));

        if (trueLabel == predictedLabel) {
            correctPredictions++;
        }
    }

    return static_cast<double>(correctPredictions) / totalSamples;
}

    int predict(const std::vector<double>& querySeries) const {
        std::vector<std::pair<int, double>> neighbors; 
        for (size_t i = 0; i < trainingSet.getNumberOfSamples(); ++i) {
            const std::vector<double>& trainingSeries = trainingSet.getData(i);
            double distance = calculateDistance(querySeries, trainingSeries);

            neighbors.push_back({trainingSet.getLabel(i), distance});
        }

        std::sort(neighbors.begin(), neighbors.end(),
                  [](const auto& a, const auto& b) { return a.second < b.second; });

        std::unordered_map<int, int> labelCount;
        for (size_t i = 0; i < k; ++i) {
            labelCount[neighbors[i].first]++;
        }
        int predictedLabel = -1;
        int maxCount = -1;

        for (const auto& entry : labelCount) {
            if (entry.second > maxCount) {
                maxCount = entry.second;
                predictedLabel = entry.first;
            }
        }

        return predictedLabel;
    }

    void setTrainingSet(const TimeSeriesDataset& trainingData) {
        trainingSet = trainingData;
    }

};

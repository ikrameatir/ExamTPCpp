#ifndef KNN_H
#define KNN_H

#include <vector>
#include <utility>
#include <algorithm> 

template<typename T>
class KNN {
protected:
    int k;

public:
    KNN() : k(1) {}
    explicit KNN(int k) : k(k) {}

    int getK() const { return k; }

    std::vector<int> findNearestNeighbours(const std::vector<T> &trainData, T& target) {
        std::vector<std::pair<double, int>> distances;

        for (size_t i = 0; i < trainData.size(); ++i) {
            double distance = similarityMeasure(target, trainData[i]);
            distances.emplace_back(distance, i);
        }

        std::sort(distances.begin(), distances.end());

        std::vector<int> neighbors;
        for (int i = 0; i < k && i < static_cast<int>(distances.size()); ++i) {
            neighbors.push_back(distances[i].second);
        }

        return neighbors;
    }

    virtual double similarityMeasure(T &a, T &b) const = 0;
};

#endif 


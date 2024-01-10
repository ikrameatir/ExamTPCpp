#ifndef KNNSTRING_H
#define KNNSTRING_H

#include "KNN.h"
#include <vector>
#include <string>
#include <algorithm>

class KNNString : public KNN<std::vector<std::string>> {
public:
    using KNN<std::vector<std::string>>::KNN;

    double similarityMeasure(std::vector<std::string> &a, std::vector<std::string> &b) const override {
        double totalDistance = 0.0;
        for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
            totalDistance += levenshteinDistance(a[i], b[i]);
        }
        return totalDistance / a.size();
    }

private:
    static int levenshteinDistance(const std::string &s1, const std::string &s2) {
        std::vector<std::vector<int>> dp(s1.length() + 1, std::vector<int>(s2.length() + 1));

        for (size_t i = 0; i <= s1.length(); ++i) dp[i][0] = i;
        for (size_t j = 0; j <= s2.length(); ++j) dp[0][j] = j;

        for (size_t i = 1; i <= s1.length(); ++i) {
            for (size_t j = 1; j <= s2.length(); ++j) {
                int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
                dp[i][j] = std::min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost });
            }
        }
        return dp[s1.length()][s2.length()];
    }
};

#endif 


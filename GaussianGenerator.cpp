#include <cmath>
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {

    
private:
    double mean;  
    double stddev;
public:

    GaussianGenerator(int seed, double mean, double stddev)
        : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {}

    std::vector<double> generateTimeSeries(int size) override {
        std::vector<double> series;
        series.reserve(size);

        std::default_random_engine generator(seed);
        std::normal_distribution<double> distribution(mean, stddev);

        for (int i = 0; i < size; ++i) {
            double u1 = static_cast<double>(rand()) / RAND_MAX;
            double u2 = static_cast<double>(rand()) / RAND_MAX;

            double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

            series.push_back(mean + stddev * z);
        }

        return series;
    }

};

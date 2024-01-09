#include <cmath>
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude; 
    double frequency; 
    double phase;   
    
public:
    SinWaveGenerator() : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

    SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
        : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

    std::vector<double> generateTimeSeries(int size) override {
        std::vector<double> series;
        series.reserve(size);

        for (int i = 0; i < size; ++i) {
            double value = amplitude * sin(frequency * i + phase);
            series.push_back(value);
        }

        return series;
    } 
};

#include "Sensor.h"
#include <cstdlib> // For random numbers
#include <ctime>

std::vector<double> Sensor::readData() {
    std::vector<double> data;
    // Simulate sensor readings: e.g., temperature and vibration.
    data.push_back(20.0 + (std::rand() % 10)); // Temperature reading
    data.push_back(0.5 + ((std::rand() % 100) / 100.0)); // Vibration level
    return data;
}

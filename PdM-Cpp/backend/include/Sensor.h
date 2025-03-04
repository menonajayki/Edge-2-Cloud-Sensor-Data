#ifndef SENSOR_H
#define SENSOR_H

#include <vector>

class Sensor {
public:
    // Simulate reading sensor data. In a real-world scenario, this might come from hardware.
    std::vector<double> readData();
};

#endif // SENSOR_H

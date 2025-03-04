#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>
#include <functional>
#include <string> 

class DataProcessor {
public:
    // Process sensor data and call the callback if an anomaly is detected.
    void processData(const std::vector<double>& data, std::function<void(const std::string&)> alertCallback);
};

#endif // DATAPROCESSOR_H

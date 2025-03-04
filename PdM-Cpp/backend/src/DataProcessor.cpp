#include "DataProcessor.h"
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

// For simplicity, we'll use a threshold-based detection.
void DataProcessor::processData(const std::vector<double>& data, std::function<void(const std::string&)> alertCallback) {
    // Process the data in a new thread.
    std::thread([data, alertCallback]() {
        // Simulate processing delay.
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        
        // Example: if temperature exceeds 25, raise an alert.
        if (data[0] > 25) {
            alertCallback("High temperature detected: " + std::to_string(data[0]));
        }
        // Example: if vibration exceeds 0.8, raise an alert.
        if (data[1] > 0.8) {
            alertCallback("High vibration detected: " + std::to_string(data[1]));
        }
    }).detach();
}

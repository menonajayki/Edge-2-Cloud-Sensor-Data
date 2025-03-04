#include "Sensor.h"
#include "DataProcessor.h"
#include "Notifier.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

int main() {
    // Seed random number generator.
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    Sensor sensor;
    DataProcessor processor;
    Notifier notifier;
    
    // Simulate continuous monitoring.
    while (true) {
        // Read sensor data.
        auto data = sensor.readData();
        
        // Process data in a separate thread. The callback notifies if anomalies are found.
        processor.processData(data, [&notifier](const std::string& msg) {
            notifier.notify(msg);
        });
        
        // Wait a bit before the next reading.
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    
    return 0;
}

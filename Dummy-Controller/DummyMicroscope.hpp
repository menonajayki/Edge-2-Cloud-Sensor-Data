#pragma once
#include <string>

class DummyMicroscope {
public:
    DummyMicroscope();
    bool initialize();
    void setPowerLevel(double level);
    std::string acquireImage(int width, int height);
    void shutdown();
};

#include "DummyMicroscope.hpp"
#include <iostream>

DummyMicroscope::DummyMicroscope() {
    // Constructor: perform any initial setup here.
}

bool DummyMicroscope::initialize() {
    std::cout << "DummyMicroscope initialized." << std::endl;
    return true;
}

void DummyMicroscope::setPowerLevel(double level) {
    std::cout << "Power level set to " << level << " units." << std::endl;
}

std::string DummyMicroscope::acquireImage(int width, int height) {
    std::cout << "Acquiring dummy image of size " << width << "x" << height << "." << std::endl;
    // For this dummy example, we simply return a file name.
    return "dummy_image.tif";
}

void DummyMicroscope::shutdown() {
    std::cout << "DummyMicroscope shutdown." << std::endl;
}

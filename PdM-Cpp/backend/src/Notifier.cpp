#include "Notifier.h"
#include <iostream>

void Notifier::notify(const std::string& message) {
    // In a real app, this might send a network request or log to a remote server.
    std::cout << "ALERT: " << message << std::endl;
}

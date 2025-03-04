cmake_minimum_required(VERSION 3.10)
project(MultiThreadExample VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard (C++11 in this case)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source file to create an executable
add_executable(MultiThreadExample Multithread.cpp)

# Find and link threads (important for multithreading on Linux/macOS)
find_package(Threads REQUIRED)
target_link_libraries(MultiThreadExample PRIVATE Threads::Threads)

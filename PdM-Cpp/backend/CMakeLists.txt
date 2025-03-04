cmake_minimum_required(VERSION 3.10)
project(PredictiveMaintenance VERSION 1.0 LANGUAGES CXX)

# Set C++ standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files.
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create the executable.
add_executable(PredictiveMaintenance ${SOURCES})

# Link threading libraries (required for multithreading).
find_package(Threads REQUIRED)
target_link_libraries(PredictiveMaintenance PRIVATE Threads::Threads)

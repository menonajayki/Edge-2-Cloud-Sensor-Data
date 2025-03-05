cmake_minimum_required(VERSION 3.21)
project(DummyMicroscopePython)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the pybind11 subdirectory.
add_subdirectory(external/pybind11)

# Create the Python module using pybind11.
pybind11_add_module(dummy_microscope bindings.cpp DummyMicroscope.cpp)

cmake_minimum_required(VERSION 3.10)
project(HelloTensorFlowCPP)

set(CMAKE_CXX_STANDARD 11)

# Set the path to your TensorFlow installation
# You need to have built or installed TensorFlow C++ (tensorflow_cc, tensorflow_framework)
# Adjust these paths to match your environment.
include_directories(/path/to/tensorflow/include)
link_directories(/path/to/tensorflow/lib)

add_executable(hello_tf main.cpp)

# Link against the TensorFlow libraries.
# Typically you need to link against tensorflow_cc and tensorflow_framework.
target_link_libraries(hello_tf tensorflow_cc tensorflow_framework)

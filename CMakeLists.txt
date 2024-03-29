# Set the minimum version of CMake that's required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(logtard VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Define source files
file(GLOB SOURCES "src/*.cpp")

# Instead of add_executable, use add_library to create a static or shared library
# For a static library, use:
add_library(logtard STATIC ${SOURCES})

# For a shared library, use:
# add_library(logtard SHARED ${SOURCES})

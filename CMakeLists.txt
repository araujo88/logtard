# Set the minimum version of CMake that's required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(logtard VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Can manually add the sources using the set command as follows:
# set(SOURCES src/main.cpp src/logger.cpp src/console_logger.cpp src/file_logger.cpp)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(logtard ${SOURCES})

# If you have any libraries to link you can use the target_link_libraries command
# target_link_libraries(logtard PRIVATE library_name)

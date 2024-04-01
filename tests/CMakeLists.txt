# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.14)

# Project name
project(logtard)

# Find the Google Test package
find_package(GTest REQUIRED)

# Include Google Test and the directories where your project headers are located
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add your test executable
add_executable(logtard_test console_logger_test.cpp)

# Link Google Test and your project's library (if applicable)
target_link_libraries(logtard_test gtest gtest_main logtard pthread) # Added gtest_main here

# Add the tests to CMake's testing framework
add_test(NAME logtard_test COMMAND logtard_test)

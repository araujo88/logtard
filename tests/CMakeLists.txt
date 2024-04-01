cmake_minimum_required(VERSION 3.14)
project(logtard_test)

# Set the C++ standard you're using
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include FetchContent module
include(FetchContent)

# Declare GoogleTest as a fetch content
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# Make GoogleTest available for use
FetchContent_MakeAvailable(googletest)

# Now you can safely link Google Test's targets
add_executable(logtard_test console_logger_test.cpp)  # Replace some_test_file.cpp with your actual test file(s)
target_link_libraries(logtard_test gtest_main logtard) # Assuming 'logtard' is your library's target name

# If your project or tests require threading, link against Threads::Threads
find_package(Threads REQUIRED)
target_link_libraries(logtard_test Threads::Threads)

# Add the tests to CMake's testing framework
include(GoogleTest)
gtest_discover_tests(logtard_test)

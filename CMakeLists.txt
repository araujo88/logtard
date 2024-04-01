cmake_minimum_required(VERSION 3.10)
project(logtard VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

# Choose one of the following depending on your needs
add_library(logtard STATIC ${SOURCES})
# add_library(logtard SHARED ${SOURCES})

add_executable(logtard_bin ${SOURCES})

target_include_directories(logtard PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Optional: Set version properties for shared libraries
if(BUILD_SHARED_LIBS)
    set_target_properties(logtard PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
    )
endif()

# Optional: Install rules
install(TARGETS logtard
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin # For Windows DLLs
)
install(DIRECTORY include/ DESTINATION include)

# Enable testing with CMake
enable_testing()

# Include the directory where the test code is located
add_subdirectory(tests)
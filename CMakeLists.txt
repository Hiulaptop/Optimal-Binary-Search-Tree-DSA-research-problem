cmake_minimum_required(VERSION 3.10)

# Project name
project(OptimalBST)

# Setup C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB SOURCE "algorithm/*.cpp")
file(GLOB MAIN "main.cpp")

set(SOURCES ${SOURCE} ${MAIN})

# Add executable
add_executable(OptimalBST ${SOURCES})

# Add header directory
target_include_directories(OptimalBST PRIVATE include)
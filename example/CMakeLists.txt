# CMakeList.txt : CMake project for Logger, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Set the project name
project(example VERSION 0.1 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wnon-virtual-dtor -Wundef -pedantic -Werror")

set(LIB_DIR ../include)
include_directories(${LIB_DIR})

# Add source to this project's executable.
add_executable (example  "main.cpp")


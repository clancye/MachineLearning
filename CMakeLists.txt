cmake_minimum_required(VERSION 3.3)
project(Machine_Learning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include)

set(SOURCE_FILES main.cpp DataUpload.cpp DataUpload.h)
add_executable(Machine_Learning ${SOURCE_FILES})
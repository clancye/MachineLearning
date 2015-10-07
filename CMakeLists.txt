cmake_minimum_required(VERSION 3.3)
project(Machine_Learning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/clancyemanuel/ClionProjects/Machine Learning/data")

find_package(Boost 1.58.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(WARNING "Boost found!")
endif()

include_directories(/usr/local/include)

set(SOURCE_FILES main.cpp DataHandler.cpp DataHandler.h Classifier.cpp Classifier.h DataGenerator.cpp DataGenerator.h Histogram.cpp Histogram.h Statistics/BetaDistribution.cpp Statistics/BetaDistribution.h)
add_executable(Machine_Learning ${SOURCE_FILES})
target_link_libraries(Machine_Learning ${Boost_LIBRARIES})
cmake_minimum_required (VERSION 2.6)
project (MedianDs)
set(CMAKE_CXX_FLAG "-g -Wall")
set(SOURCES medianDataSructure.cpp)

add_executable(MedianDs.exe medianDataSructure.cpp)

enable_testing()
add_test(RunTest MedianDs.exe)

cmake_minimum_required(VERSION 3.10)
project(IntervalTest VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(IntervalTest 
    interval_op_test.cpp
    interval_eager.cpp
)

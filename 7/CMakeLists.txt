cmake_minimum_required(VERSION 3.12)
project(7)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-g -O3")

add_executable(7 main.cpp Array.hxx Test.cpp Test.h Array.h)
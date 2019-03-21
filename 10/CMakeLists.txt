cmake_minimum_required(VERSION 3.12)
project(10)

set(CMAKE_CXX_STANDARD 17)

add_executable(10 main.cpp Solver.cpp Solver.h RandomWay.cpp RandomWay.h Algorithm.cpp Algorithm.h Common.h Eucledian.cpp Eucledian.h Metric.cpp Metric.h Point.cpp Point.h Chebyshev.cpp Chebyshev.h Manhattan.cpp Manhattan.h NeareastPoint.cpp NeareastPoint.h AllVariants.cpp AllVariants.h)
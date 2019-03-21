cmake_minimum_required(VERSION 3.12)
project(cpp_hw8)

set(CMAKE_CXX_STANDARD 17)


add_executable(cpp_hw8 main.cpp Animal.h Bear.h Man.h Pig.h Unit.h ManBearPig.h Animal.cpp Bear.cpp Man.cpp ManBearPig.cpp Pig.cpp Unit.cpp)
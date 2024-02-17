cmake_minimum_required(VERSION 3.26.4)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2 main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,1000000000")
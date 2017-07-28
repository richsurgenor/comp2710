cmake_minimum_required(VERSION 3.7)
project(lab3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Node.cpp Node.h MazeGame.cpp MazeGame.h krs0048_3p.cpp)
add_executable(lab3 ${SOURCE_FILES})
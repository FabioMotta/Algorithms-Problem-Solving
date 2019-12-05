cmake_minimum_required(VERSION 3.15)
project(Algorithms_Problem_Solving)

set(CMAKE_C_STANDARD 98)

file(GLOB SOURCES
        *.h
        *.cpp
        *.c
        )


add_executable(increasing_subsequence increasing_subsequence.cpp)
add_executable(transpose_Matrix transposeMatrix.cpp)

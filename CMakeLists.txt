cmake_minimum_required(VERSION 3.12)
project(Project5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project5
        graph.cpp
        graph.h
        minpriority.cpp
        minpriority.h
        sspapp.cpp
        sspapp.h)

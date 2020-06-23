cmake_minimum_required(VERSION 3.15)
project(no-exception-safety-template)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 14)

add_executable(no-exception-safety-template
        main.cpp)

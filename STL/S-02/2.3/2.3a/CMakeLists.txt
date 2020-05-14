cmake_minimum_required(VERSION 3.15)
project(2_3a)

if (PASS_BY_VALUE)
    add_definitions(-DPASS_BY_VALUE=${PASS_BY_VALUE})
endif()

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_3a
        main.cpp)

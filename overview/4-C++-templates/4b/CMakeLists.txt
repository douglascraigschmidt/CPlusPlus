cmake_minimum_required(VERSION 3.16)
project(4b)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(4b
        main.cpp
        stack.cpp
        stack.h
        stack.inl
        throw_exception.cpp
        throw_exception.h)

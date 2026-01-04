cmake_minimum_required(VERSION 3.10)

project(Day08)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Day08 main.cpp)

configure_file(input.txt input.txt COPYONLY)
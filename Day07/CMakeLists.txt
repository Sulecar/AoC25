cmake_minimum_required(VERSION 3.10)

project(Day07)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Day07 main.cpp)

configure_file(input.txt input.txt COPYONLY)
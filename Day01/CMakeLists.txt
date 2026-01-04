cmake_minimum_required(VERSION 3.10)

project(Day01)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Day01 main.cpp)


configure_file(input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)
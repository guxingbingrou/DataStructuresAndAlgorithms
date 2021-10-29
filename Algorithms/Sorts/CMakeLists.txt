cmake_minimum_required(VERSION 3.16)
project(skysort)


add_executable(skysort
    ${CMAKE_SOURCE_DIR}/Sort.hpp
    ${CMAKE_SOURCE_DIR}/BubbleSort.hpp
    ${CMAKE_SOURCE_DIR}/SortTest.cpp)
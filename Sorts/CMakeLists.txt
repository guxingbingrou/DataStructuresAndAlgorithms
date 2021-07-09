cmake_minimum_required(VERSION 3.16)
project(mysort)


add_executable(mysort
    ${CMAKE_SOURCE_DIR}/Sort.hpp
    ${CMAKE_SOURCE_DIR}/BubbleSort.hpp
    ${CMAKE_SOURCE_DIR}/SortTest.cpp)
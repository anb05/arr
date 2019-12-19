cmake_minimum_required(VERSION 3.16)

set(PROGECT_NAME arr)

project(${PROGECT_NAME})

set (HEADERS 
    ../arr/helpers.hpp)

set (SOURCES
    ../arr/helpers.cpp
    ../arr/main.cpp)

add_executable(${PROGECT_NAME} ${HEADERS} ${SOURCES})


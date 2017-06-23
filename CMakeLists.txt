cmake_minimum_required(VERSION 3.7)
project(socket)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp XTcp.cpp XTcp.h)
add_executable(socket ${SOURCE_FILES})
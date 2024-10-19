cmake_minimum_required(VERSION 3.20)

project(CLox VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(CLox ${SOURCES})
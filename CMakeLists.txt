cmake_minimum_required(VERSION 3.8)

project(errlib C)

set(CMAKE_C_STANDARD 99)

include(CTest)
enable_testing()
add_subdirectory(tests)

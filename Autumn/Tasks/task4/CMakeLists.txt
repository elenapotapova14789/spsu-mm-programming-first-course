cmake_minimum_required(VERSION 3.8)
project(task4)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES PrimeMersenneNumbers.c)
add_executable(task4 ${SOURCE_FILES})

target_link_libraries(task4 m)

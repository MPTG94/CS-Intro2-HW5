cmake_minimum_required(VERSION 3.15)
project(hw5 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw5q1 hw5q1.c)
target_link_libraries(hw5q1 m)
add_executable(hw5q2 hw5q2.c)
add_executable(hw5q3 hw5q3.c)

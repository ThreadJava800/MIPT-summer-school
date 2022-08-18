cmake_minimum_required(VERSION 3.0)
project(MIPT_summer_school)

set(CMAKE_CXX_STANDARD 17)

add_executable(MIPT_summer_school equation.c)

target_link_libraries(MIPT_summer_school m)

cmake_minimum_required(VERSION 3.0)
project(MIPT_summer_school)

set(CMAKE_CXX_STANDARD 17)
# "Quadratic-equation-solver/tests.cpp"
# "Quadratic-equation-solver/equation.cpp"
add_executable(MIPT_summer_school  My-string-functions/main.cpp My-string-functions/mstring.cpp My-string-functions/mstring.h)

target_link_libraries(MIPT_summer_school m)

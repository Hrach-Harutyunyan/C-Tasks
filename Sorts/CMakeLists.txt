cmake_minimum_required (VERSION 3.10)

# set the project name
project (sort)

include_directories(includes)

set (CMAKE_CXX_STANDARD 17)

# add the executable
add_executable (sort src/test.cpp)
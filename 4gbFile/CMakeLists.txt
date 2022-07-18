cmake_minimum_required (VERSION 3.10)

# set the project name
project (4BillionNumbers)


include_directories(includes)

set (CMAKE_CXX_STANDARD 17)

# add the executable
add_executable (4BillionNumbers src/test.cpp src/4billionNumbers.cpp)
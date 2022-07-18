cmake_minimum_required (VERSION 3.10)

# set the project name
project (10FilesSearch)


include_directories(includes)

set (CMAKE_CXX_STANDARD 17)

# add the executable
add_executable (10FilesSearch src/test.cpp src/10filesSearch.cpp)
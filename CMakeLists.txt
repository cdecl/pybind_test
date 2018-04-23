cmake_minimum_required(VERSION 3.5)

project(sbind)

#add_subdirectory(/subdir)


set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")

include_directories(/usr/include/python3.5m/ pybind11/include )
link_directories( )
link_libraries( )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB src "src/*.cpp")

add_library(sbind SHARED ${src})
set_target_properties(sbind PROPERTIES PREFIX "")

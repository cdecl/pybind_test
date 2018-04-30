cmake_minimum_required(VERSION 3.5)

project(sbind)

#add_subdirectory(/subdir)
set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")

find_package(PythonLibs 3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS} pybind11/include )
link_directories( )
link_libraries( )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB src "src/*.cpp")

add_library(sbind SHARED ${src})
set_target_properties(sbind PROPERTIES PREFIX "")

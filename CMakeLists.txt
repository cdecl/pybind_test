cmake_minimum_required(VERSION 3.5)

project(sbind)

#add_subdirectory(/subdir)
<<<<<<< HEAD
set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")

find_package(PythonLibs 3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS} pybind11/include )
link_directories( )
link_libraries( )
=======

set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")

if (APPLE)
    include_directories(/usr/local/Cellar/python/3.6.5/Frameworks/Python.framework/Versions/3.6/include/python3.6m pybind11/include )
    link_directories(/usr/local/Cellar/python/3.6.5/Frameworks/Python.framework/Versions/3.6/lib)
    link_libraries(-lpython3.6 )
else()
    include_directories(/usr/include/python3.5m pybind11/include )
endif()

>>>>>>> 2e7d23b5c6f268ac1fce15ff55524ca186d9dfe0

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB src "src/*.cpp")

add_library(sbind SHARED ${src})
set_target_properties(sbind PROPERTIES PREFIX "")

if (APPLE)
    add_custom_command(TARGET sbind 
        POST_BUILD
        COMMAND  cp ${CMAKE_BINARY_DIR}/lib/sbind.dylib ${CMAKE_BINARY_DIR}/lib/sbind.so 
    )
endif()
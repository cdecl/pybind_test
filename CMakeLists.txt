cmake_minimum_required(VERSION 3.5)

project(sbind)

#add_subdirectory(/subdir)

set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")

if (APPLE)
    include_directories(/usr/local/Cellar/python/3.6.5/Frameworks/Python.framework/Versions/3.6/include/python3.6m pybind11/include )
    link_directories(/usr/local/Cellar/python/3.6.5/Frameworks/Python.framework/Versions/3.6/lib)
    link_libraries(-lpython3.6 )
else()
    include_directories(pybind11/include )
endif()


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
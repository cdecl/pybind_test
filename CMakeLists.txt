cmake_minimum_required(VERSION 3.5)

project(sbind)

#add_subdirectory(/subdir)
set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")

find_package(PythonLibs 3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS} pybind11/include )
link_directories( )
link_libraries(${PYTHON_LIBRARIES} )
<<<<<<< HEAD

=======
message(${PYTHON_LIBRARIES})
>>>>>>> 880dd116692e7e1b4df9cd43e516f44cfa68e57b
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

cmake_minimum_required(VERSION 3.10)

set(target_name connect_4)
project(${target_name})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCE_FILES
    main.cpp
)

message(STATUS "CMake Binary Directory: ${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${target_name} ${SOURCE_FILES})

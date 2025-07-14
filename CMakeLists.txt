cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(RayTracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF) # prohibits compiler quirks

set( SOURCE_RAY_TRACE
    src/main.cpp
)

include_directories(src)

# compiler information
message(STATUS "Compiler: " ${CMAKE_CXX_COMPILER_ID})
message(STATUS "Debug: " ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "Release: " ${CMAKE_CXX_FLAGS_RELEASE})

# executables to be created
add_executable(RayTraceExecutable ${SOURCE_RAY_TRACE})
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_FILES)
add_executable(app ${SRC_FILES})
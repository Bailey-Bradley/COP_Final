cmake_minimum_required(VERSION 3.10.0)
project(cop_final VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(cop_final ${SRC_FILES})
target_include_directories(cop_final PRIVATE "${CMAKE_SOURCE_DIR}/src")

unset(SRC_FILES)
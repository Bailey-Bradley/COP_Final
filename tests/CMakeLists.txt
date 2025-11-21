cmake_minimum_required(VERSION 3.10.0)
project(tests VERSION 0.1.0 LANGUAGES C CXX)

add_executable(tests tests.cpp)
target_include_directories(tests PRIVATE "${CMAKE_SOURCE_DIR}/src")

add_custom_command(
    TARGET tests
    POST_BUILD
    COMMAND tests --success
)
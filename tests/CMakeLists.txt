cmake_minimum_required(VERSION 3.10.0)
project(tests VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB TEST_SRC "${CMAKE_SOURCE_DIR}/tests/*.cpp")
file(GLOB APP_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")

list(REMOVE_ITEM APP_SRC "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(tests ${TEST_SRC} ${APP_SRC})

target_include_directories(tests PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/tests"
)

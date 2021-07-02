cmake_minimum_required(VERSION 3.0)

project(game)

add_compile_options("-wall -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

add_executable(game main.cpp)

target_include_directories()
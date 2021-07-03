cmake_minimum_required(VERSION 3.0)

project(game)

#add_compile_options("-wall -std=c++11")

#set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(./Creature)
add_subdirectory(./Adventure)

#target_include_directories(creature_library PUBLIC ./public)
include_directories(./Creature/public)
include_directories(./Adventure/public)

add_executable(game main.cpp)

target_link_libraries(game creature_library)
target_link_libraries(game adventure_library)
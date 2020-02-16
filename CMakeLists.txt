cmake_minimum_required(VERSION 3.10)
project(Trunk)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-std=c++17)

add_definitions(-Wall)

add_subdirectory(Test)

add_executable(Trunk main.cpp)

target_link_libraries(Trunk HelperFunction)
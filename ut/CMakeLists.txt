cmake_minimum_required(VERSION 3.10)
project(Trunk_UT)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-std=c++17)


add_executable(Trunk_UT BoxTest.cpp)

target_link_libraries(Trunk_UT
    pthread
    gmock
    gtest
)
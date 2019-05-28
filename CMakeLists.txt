cmake_minimum_required(VERSION 3.10)
project(Trunk)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-std=c++17)

add_executable(Trunk main.cpp TrunkLoad.h   Box.h Package.h)
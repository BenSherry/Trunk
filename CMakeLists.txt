cmake_minimum_required(VERSION 3.13)
project(Trunk)

set(CMAKE_CXX_STANDARD 17)

add_executable(Trunk main.cpp TrunkLoad.h TrunkLoad.cpp  Box.h Package.h)
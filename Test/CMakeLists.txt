cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

add_definitions(-std=c++17)

add_definitions(-Wall)

aux_source_directory(. DIR_LIB_SRCS)
# 生成链接库
add_library (HelperFunction ${DIR_LIB_SRCS})
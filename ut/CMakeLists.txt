cmake_minimum_required(VERSION 3.10)
project(FirstUT)
find_package (Threads)
set(CMAKE_CXX_STANDARD 17)
add_definitions(-std=c++17)
INCLUDE_DIRECTORIES(/usr/include/lib)
link_directories(/usr/local/lib)
include_directories($ENV{GTEST_ROOT}/include)
link_directories($ENV{GTEST_ROOT}/build/lib)

add_executable(FirstUT FirstUT.cpp)
target_link_libraries(FirstUT gtest gtest_main) #\u6ce8\u610f\u8fd9\u91cc
target_link_libraries(FirstUT ${CMAKE_THREAD_LIBS_INIT})

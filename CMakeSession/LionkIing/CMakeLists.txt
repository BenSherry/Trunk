cmake_minimum_required(VERSION 3.25)
project(Lionking)
set(CMAKE_CXX_STANDARD 17)
MESSAGE(STATUS "this is BINARY dir:" ${PROJECT_BINARY_DIR})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
ADD_SUBDIRECTORY(src bin)
INSTALL(PROGRAMS runhello.sh DESTINATION bin)
INSTALL(DIRECTORY doc/ DESTINATION share/doc)
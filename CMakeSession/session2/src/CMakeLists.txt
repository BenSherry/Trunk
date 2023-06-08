INCLUDE_DIRECTORIES(/workspaces/include)
LINK_DIRECTORIES(/workspaces/lib)
ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main libhello.so)
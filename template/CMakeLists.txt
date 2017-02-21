cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME template)

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter -lGL -lGLU -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi")

add_executable(${PROJECT_NAME} main.cpp)

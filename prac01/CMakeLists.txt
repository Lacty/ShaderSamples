cmake_minimum_required(VERSION 2.8)

project(prac01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -lGL -lGLU -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi")

add_executable(prac01 main.cpp)

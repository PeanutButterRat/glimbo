cmake_minimum_required(VERSION 4.3)
project(glimbo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src/external/pybind11)

pybind11_add_module(glimbo src/main.cpp)

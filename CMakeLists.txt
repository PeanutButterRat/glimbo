cmake_minimum_required(VERSION 4.3)
project(glimbo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

set(THIRD_PARTY_LIBRARY_DIRECTORY ${CMAKE_SOURCE_DIR}/src/external)

add_subdirectory(${THIRD_PARTY_LIBRARY_DIRECTORY}/pybind11)

set(SDL_SHARED OFF)
set(SDL_STATIC ON)
add_subdirectory(${THIRD_PARTY_LIBRARY_DIRECTORY}/SDL)

# glad (doesn't work with add_subdirectory).
add_library(glad
        ${THIRD_PARTY_LIBRARY_DIRECTORY}/glad/src/glad.c
)
target_include_directories(glad PUBLIC
        ${THIRD_PARTY_LIBRARY_DIRECTORY}/glad/include
)

pybind11_add_module(glimbo src/main.cpp)

target_link_libraries(glimbo PRIVATE
        glad
        SDL3::SDL3
)
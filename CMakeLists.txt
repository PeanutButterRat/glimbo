cmake_minimum_required(VERSION 4.3)
project(glimbo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

set(LIBRARY_NAME ${PROJECT_NAME}lib)
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

add_library(${LIBRARY_NAME}
        src/glimbo/window.cpp
        src/glimbo/engine.cpp
)

target_include_directories(${LIBRARY_NAME} PUBLIC
        src
)

target_link_libraries(${LIBRARY_NAME} PRIVATE
        glad
        SDL3::SDL3
)

pybind11_add_module(${PROJECT_NAME} src/bindings/module.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_NAME})

cmake_minimum_required(VERSION 4.3)
project(glimbo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS OFF)

set(LIBRARY_NAME ${PROJECT_NAME}lib)
set(THIRD_PARTY_LIBRARY_DIRECTORY ${CMAKE_SOURCE_DIR}/src/external)

add_subdirectory(${THIRD_PARTY_LIBRARY_DIRECTORY}/assimp)
add_subdirectory(${THIRD_PARTY_LIBRARY_DIRECTORY}/glm)
add_subdirectory(${THIRD_PARTY_LIBRARY_DIRECTORY}/pybind11)
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
        src/glimbo/mesh.cpp
        src/glimbo/shader.cpp
        src/glimbo/math.cpp
        src/glimbo/camera.cpp
)

target_include_directories(${LIBRARY_NAME} PUBLIC
        src
)

target_link_libraries(${LIBRARY_NAME} PUBLIC
        assimp
        glad
        glm
        SDL3::SDL3
        pybind11::pybind11
)

pybind11_add_module(${PROJECT_NAME} src/bindings/glimbo.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_NAME})

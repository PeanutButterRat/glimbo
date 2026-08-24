cmake_minimum_required(VERSION 4.3)
project(glimbo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS OFF)

set(LIBRARY_NAME ${PROJECT_NAME}lib)
set(PACKAGE_NAME ${PROJECT_NAME}py)
set(THIRD_PARTY_LIBRARY_DIRECTORY ${CMAKE_SOURCE_DIR}/src/external)
set(IMGUI_DIRECTORY ${THIRD_PARTY_LIBRARY_DIRECTORY}/imgui)

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

# ImGui (also doesn't work with add_subdirectory).
add_library(imgui
        ${IMGUI_DIRECTORY}/imgui.cpp
        ${IMGUI_DIRECTORY}/imgui_demo.cpp
        ${IMGUI_DIRECTORY}/imgui_draw.cpp
        ${IMGUI_DIRECTORY}/imgui_tables.cpp
        ${IMGUI_DIRECTORY}/imgui_widgets.cpp
        ${IMGUI_DIRECTORY}/backends/imgui_impl_sdl3.cpp
        ${IMGUI_DIRECTORY}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC
        ${IMGUI_DIRECTORY}
        ${IMGUI_DIRECTORY}/backends
)
target_link_libraries(imgui PUBLIC SDL3::SDL3)

add_library(${LIBRARY_NAME}
        src/glimbo/window.cpp
        src/glimbo/engine.cpp
        src/glimbo/mesh.cpp
        src/glimbo/shader.cpp
        src/glimbo/math.cpp
        src/glimbo/camera.cpp
        src/glimbo/object.cpp
        src/glimbo/component.cpp
        src/glimbo/scene.cpp
        src/glimbo/element.cpp
        src/glimbo/mouse.cpp
        src/glimbo/keyboard.cpp
        src/glimbo/editor.cpp
)

target_include_directories(${LIBRARY_NAME} PUBLIC src)

target_link_libraries(${LIBRARY_NAME} PUBLIC
        assimp
        glad
        glm
        imgui
        SDL3::SDL3
)

# Python package.
pybind11_add_module(${PACKAGE_NAME} src/bindings/glimbo.cpp)

target_link_libraries(${PACKAGE_NAME} PRIVATE ${LIBRARY_NAME})

# Main executable.
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${LIBRARY_NAME}
)

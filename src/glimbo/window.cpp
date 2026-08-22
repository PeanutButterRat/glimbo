#include "window.h"

#include <stdexcept>

#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl3.h>

using namespace glimbo;

Window::Window(const int width, const int height, const std::string &title) : width(width), height(height) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        throw std::runtime_error("Could not initialize SDL.");
    }

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    sdl = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL);

    if (!sdl) {
        throw std::runtime_error("Could not create SDL window.");
    }

    SDL_GLContext context = SDL_GL_CreateContext(sdl);
    if (!context) {
        throw std::runtime_error("Could not create SDL context.");
    }

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress))) {
        throw std::runtime_error("Could not initialize GLAD.");
    }

    glViewport(0, 0, width, height);
    glClearColor(0, 0, 0, 1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForOpenGL(sdl, context);
    ImGui_ImplOpenGL3_Init();
}

Window::~Window() {
    if (sdl) {
        SDL_DestroyWindow(sdl);
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
    };
}

void Window::bind(py::module_ &m) {
    py::class_<Window>(m, "Window")
        .def("clear", &Window::clear)
        .def("refresh", &Window::refresh);
}

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
    window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL);

    if (!window) {
        throw std::runtime_error("Could not create SDL window.");
    }

    context = SDL_GL_CreateContext(window);
    if (!context) {
        throw std::runtime_error("Could not create SDL context.");
    }

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress))) {
        throw std::runtime_error("Could not initialize GLAD.");
    }

    glViewport(0, 0, width - 200, height);
    glClearColor(0, 0, 0, 1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init();
}

Window::~Window() {
    if (window) {
        SDL_DestroyWindow(window);
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();

        SDL_GL_DestroyContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    };
}

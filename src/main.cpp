#include <pybind11/pybind11.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

namespace py = pybind11;

void hello() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window *sdl = SDL_CreateWindow("Glimbo Game Engine", 900, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(sdl);
    gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);

    glViewport(0, 0, 900, 600);
    glClearColor(0, 0, 0, 1);
}

PYBIND11_MODULE(glimbo, m, py::mod_gil_not_used()) {
    m.def("hello", &hello);
}

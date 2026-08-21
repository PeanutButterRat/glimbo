#include "engine.h"

#include <SDL3/SDL.h>

using namespace glimbo;

Engine::Engine() : window(1000, 800, "Glimbo Game Engine") {}

static float calculate_dt() {
    static Uint64 previous_frame = SDL_GetPerformanceCounter();
    const Uint64 now = SDL_GetPerformanceCounter();
    const float dt = static_cast<float>(now - previous_frame) / static_cast<float>(SDL_GetPerformanceFrequency());
    previous_frame = now;

    return dt;
}

void Engine::update() {
    const float dt = calculate_dt();

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            exit(0);
        }
    }
}

void Engine::bind(py::module_ &m) {
    py::class_<Engine>(m, "Engine")
        .def(py::init<>()).def("update", &Engine::update)
        .def_readonly("window", &Engine::window);
}

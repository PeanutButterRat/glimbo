#include "engine.h"

#include <SDL3/SDL.h>

using namespace glimbo;

Engine::Engine() : window(1000, 800, "Glimbo Game Engine") {}

static float delta() {
    static Uint64 previous = SDL_GetPerformanceCounter();
    const Uint64 now = SDL_GetPerformanceCounter();
    const float dt = static_cast<float>(now - previous) / static_cast<float>(SDL_GetPerformanceFrequency());
    previous = now;

    return dt;
}

float Engine::update() const {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            exit(0);
        }
    }

    const float dt = delta();
    scene.update(dt);

    return dt;
}

void Engine::bind(py::module_ &m) {
    py::class_<Engine>(m, "Engine")
            .def(py::init<>())
            .def("update", &Engine::update)
            .def_readonly("window", &Engine::window)
            .def_readonly("scene", &Engine::scene);
}

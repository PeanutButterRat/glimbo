#include "engine.h"

#include <SDL3/SDL.h>

using namespace glimbo;

Engine::Engine() : window(1000, 800, "Glimbo Game Engine") {}

void Engine::update() {
    const uint64_t now = SDL_GetPerformanceCounter();
    const float dt = static_cast<float>(last_frame - now) / static_cast<float>(SDL_GetPerformanceFrequency());
    last_frame = now;

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            exit(0);
        }
    }
}

void Engine::run() {
    while (true) {
        update();
    }
}

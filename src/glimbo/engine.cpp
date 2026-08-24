#include "engine.h"

#include <SDL3/SDL.h>
#include <imgui_impl_sdl3.h>

using namespace glimbo;

Engine::Engine() : window(1200, 800, "Glimbo Game Engine") {}

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
        ImGui_ImplSDL3_ProcessEvent(&event);

        switch (event.type) {
            case SDL_EVENT_QUIT:
                exit(0);
                break;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                mouse.handle(event);
                break;
        }
    }

    const float dt = delta();
    scene.update(dt);

    return dt;
}

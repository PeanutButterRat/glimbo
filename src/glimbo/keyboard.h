#pragma once

#include <SDL3/SDL.h>

#include "glimbo/event.h"

namespace glimbo {
    struct Keyboard {
        Event<int> pressed;

        void handle(const SDL_Event &event) const;
    };
} // namespace glimbo

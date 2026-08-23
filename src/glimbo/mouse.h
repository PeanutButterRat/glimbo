#pragma once

#include <SDL3/SDL_events.h>

#include "glimbo/event.h"

namespace glimbo {
    struct Mouse {
        Event<float, float> pressed;

        void handle(const SDL_Event &event) const;
    };
} // namespace glimbo

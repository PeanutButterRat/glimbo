#pragma once

#include <SDL3/SDL_events.h>

#include "glimbo/event.h"

namespace glimbo {
    struct Mouse {
        enum struct Button;

        Event<Button> pressed;
        Event<Button> released;
        Event<float, float> moved;
        Event<int> scrolled;

        void handle(const SDL_Event &event) const;
    };

    enum struct Mouse::Button {
        LEFT = SDL_BUTTON_LEFT,
        MIDDLE = SDL_BUTTON_MIDDLE,
        RIGHT = SDL_BUTTON_RIGHT,
        X1 = SDL_BUTTON_X1,
        X2 = SDL_BUTTON_X2,
    };
} // namespace glimbo

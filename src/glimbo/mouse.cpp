#include "mouse.h"

using namespace glimbo;

void Mouse::handle(const SDL_Event &event) const {
    switch (event.type) {
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            pressed.handle(static_cast<Button>(event.button.button));
            break;
        case SDL_EVENT_MOUSE_BUTTON_UP:
            released.handle(static_cast<Button>(event.button.button));
            break;
        case SDL_EVENT_MOUSE_MOTION:
            moved.handle(event.motion.xrel, event.motion.yrel);
            break;
        case SDL_EVENT_MOUSE_WHEEL:
            scrolled.handle(event.wheel.integer_y);
            break;
    }
}

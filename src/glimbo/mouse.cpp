#include "mouse.h"

using namespace glimbo;

void Mouse::handle(const SDL_Event &event) const {
    switch (event.type) {
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            pressed.handle(event.button.x, event.button.y);
            break;
    }
}

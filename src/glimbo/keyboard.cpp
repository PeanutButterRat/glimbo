#include "keyboard.h"

using namespace glimbo;

void Keyboard::handle(const SDL_Event &event) const {
    switch (event.type) {
        case SDL_EVENT_KEY_DOWN:
            pressed.handle(event.key.key);
            break;
    }
}

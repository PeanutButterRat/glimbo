#pragma once

#include <string>

struct SDL_Window;

namespace glimbo {
    struct Window {
        Window(int width, int height, const std::string &title);

        ~Window();

    private:
        int width;
        int height;
        SDL_Window *sdl_window;
    };
} // namespace glimbo

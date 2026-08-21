#pragma once

#include <string>

#include <SDL3/SDL.h>
#include <glad/glad.h>

struct SDL_Window;

namespace glimbo {
    struct Window {
        Window(int width, int height, const std::string &title);

        void clear() const { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

        void refresh() const { SDL_GL_SwapWindow(sdl_window); }

        ~Window();

    private:
        int width;
        int height;
        SDL_Window *sdl_window;
    };
} // namespace glimbo

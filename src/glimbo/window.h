#pragma once

#include <string>

#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "glimbo/common.h"

struct SDL_Window;

namespace glimbo {
    struct Window {
        Window(int width, int height, const std::string &title);

        void clear() const { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

        void refresh() const { SDL_GL_SwapWindow(window); }

        ~Window();

        static void bind(py::module_ &m);

    private:
        int width;
        int height;
        SDL_Window *window;
        SDL_GLContext context;
    };
} // namespace glimbo

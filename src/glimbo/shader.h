#pragma once

#include <string>

#include <glad/glad.h>

namespace glimbo {
    struct Shader {
        GLuint id = 0;

        Shader(const std::string &vertex, const std::string &fragment);

        void use() const { glUseProgram(id); }

        ~Shader() { glDeleteProgram(id); };

    private:
        struct GLSLShader {
            GLuint id = 0;

            GLSLShader(const std::string &shader, GLenum type);

            ~GLSLShader() { glDeleteShader(id); };
        };
    };
} // namespace glimbo

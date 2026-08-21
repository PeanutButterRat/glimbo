#pragma once

#include <string>

#include <glad/glad.h>

#include "glimbo/common.h"
#include "glimbo/math.h"

namespace glimbo {
    struct Shader {
        GLuint id = 0;

        Shader(const std::string &vertex, const std::string &fragment);

        void use() const { glUseProgram(id); }

        void set(const std::string &uniform, const Matrix &value) const;

        ~Shader() { glDeleteProgram(id); };

    private:
        struct GLSLShader {
            GLuint id = 0;

            GLSLShader(const std::string &shader, GLenum type);

            ~GLSLShader() { glDeleteShader(id); };
        };

    public:
        static void bind(py::module_ &m);
    };
} // namespace glimbo

#pragma once

#include <string>
#include <vector>

#include <glad/glad.h>

#include "glimbo/common.h"
#include "glimbo/math.h"

namespace glimbo {
    class Mesh {
        std::vector<Vec3> vertices;
        std::vector<unsigned> indices;

        GLuint vao = 0;
        GLuint vbo = 0;
        GLuint ebo = 0;

    public:
        Mesh(const std::string &filepath);

        void draw() const;

        ~Mesh();

        static void bind(py::module_ &m);
    };
} // namespace glimbo

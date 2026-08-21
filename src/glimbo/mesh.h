#pragma once

#include <string>
#include <vector>

#include <glad/glad.h>

#include "glimbo/common.h"

namespace glimbo {
    struct Shader;

    class Mesh {
        struct Vertex {
            float x, y, z;

            Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
        };

        std::vector<Vertex> vertices;
        std::vector<unsigned> indices;

        GLuint vao = 0;
        GLuint vbo = 0;
        GLuint ebo = 0;

    public:
        Mesh(const std::string &filepath);

        void draw(const Shader &shader) const;

        ~Mesh();

        static void bind(py::module_ &m);
    };
} // namespace glimbo

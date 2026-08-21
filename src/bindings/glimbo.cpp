#include "glimbo/camera.h"
#include "glimbo/common.h"
#include "glimbo/engine.h"
#include "glimbo/math.h"
#include "glimbo/mesh.h"
#include "glimbo/shader.h"
#include "glimbo/window.h"

using namespace glimbo;

PYBIND11_MODULE(glimbo, m, py::mod_gil_not_used()) {
    Engine::bind(m);
    Window::bind(m);
    Camera::bind(m);
    Mesh::bind(m);
    Shader::bind(m);
    bind_math(m);
}

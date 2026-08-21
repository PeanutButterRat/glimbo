#include "math.h"

using namespace glimbo;

void bind_vec2(py::module_ &m) {
    py::class_<Vec2>(m, "Vec2")
        .def(py::init<float, float>())
        .def_readwrite("x", &Vec2::x)
        .def_readwrite("y", &Vec2::y);
}

void bind_vec3(py::module_ &m) {
    py::class_<Vec3>(m, "Vec3")
        .def(py::init<float, float, float>())
        .def_readwrite("x", &Vec3::x)
        .def_readwrite("y", &Vec3::y)
        .def_readwrite("z", &Vec3::z);
}

void bind_matrix(py::module_ &m) {
    py::class_<Matrix>(m, "Matrix");

}

void glimbo::bind_math(py::module_ &m) {
    bind_vec2(m);
    bind_vec3(m);
    bind_matrix(m);
}

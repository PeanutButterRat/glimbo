#include "math.h"

void glimbo::bind_math(py::module_ &m) {
    py::class_<Vec2>(m, "Vec2")
        .def(py::init<float, float>())
        .def_readwrite("x", &Vec2::x)
        .def_readwrite("y", &Vec2::y);
}

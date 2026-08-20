#include <pybind11/pybind11.h>

#include "glimbo/engine.h"

namespace py = pybind11;

PYBIND11_MODULE(glimbo, m, py::mod_gil_not_used()) {
    py::class_<glimbo::Engine>(m, "Engine")
        .def(py::init<>())
        .def("run", &glimbo::Engine::run);
}

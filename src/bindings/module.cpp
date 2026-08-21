#include <pybind11/pybind11.h>

#include "glimbo/engine.h"
#include "glimbo/shader.h"
#include "glimbo/mesh.h"

namespace py = pybind11;

using namespace glimbo;

PYBIND11_MODULE(glimbo, m, py::mod_gil_not_used()) {
    py::class_<Engine>(m, "Engine")
        .def(py::init<>())
        .def("update", &Engine::update)
        .def_readonly("window", &Engine::window);

    py::class_<Window>(m, "Window")
        .def("clear", &Window::clear)
        .def("refresh", &Window::refresh);

    py::class_<Shader>(m, "Shader")
        .def(py::init<const std::string &, const std::string &>());

    py::class_<Mesh>(m, "Mesh")
        .def(py::init<const std::string &>())
        .def("draw", &Mesh::draw);
}

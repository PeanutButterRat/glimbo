#include <pybind11/pybind11.h>

namespace py = pybind11;

void hello() {
    py::print("Hello, Python!");
}

PYBIND11_MODULE(glimbo, m, py::mod_gil_not_used()) {
    m.def("hello", &hello);
}

#include "shader.h"

#include <stdexcept>

using namespace glimbo;

Shader::Shader(const std::string &vertex, const std::string &fragment) {
    const GLSLShader vs{vertex, GL_VERTEX_SHADER};
    const GLSLShader fs{fragment, GL_FRAGMENT_SHADER};

    id = glCreateProgram();
    glAttachShader(id, vs.id);
    glAttachShader(id, fs.id);
    glLinkProgram(id);

    GLint successful = 0;
    glGetProgramiv(id, GL_LINK_STATUS, &successful);

    if (!successful) {
        glDeleteProgram(id);
        throw std::runtime_error("failed to link shader program");
    }
}

void Shader::set(const std::string &uniform, const Matrix &value) const {
    glUseProgram(id);
    const int location = glGetUniformLocation(id, uniform.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}

Shader::GLSLShader::GLSLShader(const std::string &shader, const GLenum type) {
    const char *source = shader.c_str();
    id = glCreateShader(type);
    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    GLint successful = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &successful);

    if (!successful) {
        glDeleteShader(id);
        throw std::runtime_error("failed to compile shader");
    }
}

void Shader::bind(py::module_ &m) {
    py::class_<Shader>(m, "Shader")
        .def(py::init<const std::string &, const std::string &>())
        .def("set", &Shader::set);
}

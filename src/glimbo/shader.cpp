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

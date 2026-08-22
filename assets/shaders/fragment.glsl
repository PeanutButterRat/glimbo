#version 460 core
out vec4 color;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main() {
    color = vec4(1, 0, 0, 1);
}

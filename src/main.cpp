#include <fstream>
#include <iostream>

#include "glimbo/common.h"
#include "glimbo/engine.h"

using namespace glimbo;

static std::string read(const std::string &filepath) {
    std::ifstream file(filepath);
    std::string line;
    std::stringstream data;

    while (std::getline(file, line)) {
        data << line << "\n";
    }

    return data.str();
}

int main() {
    Engine engine;
    auto mesh = std::make_shared<Mesh>("assets/models/cube.glb");
    const std::string vertex = read("assets/shaders/vertex.glsl");
    const std::string fragment = read("assets/shaders/fragment.glsl");
    auto shader = std::make_shared<Shader>(vertex, fragment);
    auto model = std::make_shared<Model>(mesh, shader);

    auto cube = std::make_shared<Object>();
    cube->add(model);
    engine.scene.add(cube);
    engine.scene.camera.position.z += 10;

    while (true) {
        engine.update();
        engine.window.clear();
        engine.scene.draw();
        engine.window.refresh();
    }

    return 0;
}

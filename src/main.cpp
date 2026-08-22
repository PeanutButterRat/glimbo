#include <fstream>
#include <iostream>

#include "glimbo/common.h"
#include "glimbo/element.h"
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

    engine.scene.camera.position += Vec3(0, 2, 10);
    engine.scene.camera.rotation.x -= 10;

    auto panel = std::make_shared<Panel>();
    panel->position.x = 1000;
    panel->size = {200, 800};
    engine.scene.add(panel);

    auto button = std::make_shared<Button>();
    button->label = "Toggle Visibility";
    button->callback = [&cube]() -> void { cube->visible = !cube->visible; };
    panel->add(button);

    engine.callbacks.emplace_back([](float x, float y) -> void {
        std::cout << x << ' ' << y << std::endl;
    });

    while (true) {
        float dt = engine.update();
        cube->rotation.y += dt * 90;
        engine.window.clear();
        engine.scene.draw();
        engine.window.refresh();
    }

    return 0;
}

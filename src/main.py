import glimbo


def main():
    engine = glimbo.Engine()
    vertex = open("assets/shaders/vertex.glsl").read()
    fragment = open("assets/shaders/fragment.glsl").read()
    mesh = glimbo.Mesh("assets/models/cube.glb")
    shader = glimbo.Shader(vertex, fragment)

    vector = glimbo.Vec2(1, 2)
    print(vector, vector.x, vector.y)

    while True:
        engine.update()
        engine.window.clear()
        mesh.draw(shader)
        engine.window.refresh()


if __name__ == "__main__":
    main()

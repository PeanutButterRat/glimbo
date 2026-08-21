import glimbo


def main():
    engine = glimbo.Engine()
    vertex = open("assets/shaders/vertex.glsl").read()
    fragment = open("assets/shaders/fragment.glsl").read()
    mesh = glimbo.Mesh("assets/models/cube.glb")
    shader = glimbo.Shader(vertex, fragment)
    model = glimbo.Model(mesh, shader)
    cube = glimbo.Object()

    cube.add(model)
    engine.scene.add(cube)

    while True:
        engine.update()
        engine.window.clear()
        engine.scene.draw()
        engine.window.refresh()


if __name__ == "__main__":
    main()

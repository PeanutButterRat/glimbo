#include "mesh.h"

#include <stdexcept>

#include <assimp/cimport.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "glimbo/shader.h"

glimbo::Mesh::Mesh(const std::string &filepath) {
    const aiScene *scene = aiImportFile(filepath.c_str(), aiProcess_CalcTangentSpace | aiProcess_Triangulate);

    if (!scene) {
        throw std::runtime_error("failed to load mesh from file");
    }

    for (size_t i = 0; i < scene->mNumMeshes; i++) {
        const aiMesh *mesh = scene->mMeshes[i];

        for (size_t j = 0; j < mesh->mNumVertices; j++) {
            const aiVector3D vertex = mesh->mVertices[j];
            vertices.emplace_back(vertex.x, vertex.y, vertex.z);
        }

        for (size_t j = 0; j < mesh->mNumFaces; j++) {
            const aiFace face = mesh->mFaces[j];
            for (unsigned int k = 0; k < face.mNumIndices; k++) {
                indices.emplace_back(face.mIndices[k]);
            }
        }
    }

    aiReleaseImport(scene);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizei>(vertices.size() * sizeof(float)), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizei>(indices.size() * sizeof(unsigned)), indices.data(), GL_STATIC_DRAW);
}

void glimbo::Mesh::draw(const Shader &shader) const {
    shader.use();
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, nullptr);
}

glimbo::Mesh::~Mesh() {
    glDeleteBuffers(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

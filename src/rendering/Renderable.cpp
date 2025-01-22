#include "../../include/Renderable.h"
#include <cstddef>
#include <glm/detail/setup.hpp>
#include <iostream>

using namespace glm;

std::vector<Renderable*> Renderable::_renderables;

Renderable::Renderable(
    float* vertices, size_t verticesSize,
    uint* indices, size_t indicesSize,
    vec3 position
) {
    this->_vertices = vertices;
    this->_verticesSize = verticesSize;
    this->_indices = indices;
    this->_indicesSize = indicesSize;
    this->_position = position;
    _renderables.push_back(this);
}
Renderable::Renderable(
    Shapes shape, vec3 position, vec3 color
) {
    this->_position = position;

    if (shape == CUBE) {
        this->_vertices = new float[48] {
            position.x - 0.5f, position.y - 0.5f, position.y - 0.5f,   color.r, color.g, color.b,
            position.x + 0.5f, position.y - 0.5f, position.y - 0.5f,   color.r, color.g, color.b,
            position.x + 0.5f, position.y + 0.5f, position.y - 0.5f,   color.r, color.g, color.b,
            position.x - 0.5f, position.y + 0.5f, position.y - 0.5f,   color.r, color.g, color.b,
            position.x - 0.5f, position.y - 0.5f, position.y + 0.5f,   color.r, color.g, color.b,
            position.x + 0.5f, position.y - 0.5f, position.y + 0.5f,   color.r, color.g, color.b,
            position.x + 0.5f, position.y + 0.5f, position.y + 0.5f,   color.r, color.g, color.b,
            position.x - 0.5f, position.y + 0.5f, position.y + 0.5f,   color.r, color.g, color.b,
        };
        this->_verticesSize = 48;

        this->_indices = new unsigned int[36] {
              0, 1, 3, 1, 2, 3,
              4, 5, 7, 5, 6, 7,
              4, 5, 1, 4, 1, 0,
              3, 2, 6, 3, 6, 7,
              4, 0, 3, 4, 3, 7,
              1, 5, 6, 1, 6, 2
          };
        this->_indicesSize = 36;
    }

    _renderables.push_back(this);

}
void Renderable::bind() {
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    glGenBuffers(1, &_EBO);

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, _verticesSize * sizeof(float), _vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indicesSize * sizeof(uint), _indices, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderable::translate(vec3 direction) {

}

void Renderable::render() {
    if (_shader != nullptr) {
        _shader->bind();
    }

    glBindVertexArray(_VAO);
    glDrawElements(GL_TRIANGLES, _indicesSize, GL_UNSIGNED_INT, 0);
}

void Renderable::enableRendering() {
    _renderingEnabled = true;
}

void Renderable::disableRendering() {
    _renderingEnabled = false;

}

bool Renderable::isRenderingEnabled() {
    return _renderingEnabled;
}

void Renderable::bindAll() {
    for (Renderable* renderable: _renderables) {
        renderable->bind();
    }
}
void Renderable::renderAll() {
    for (Renderable* renderable: _renderables) {
        if (renderable->isRenderingEnabled()) {

            renderable->render();
        }
    }
}

Renderable::~Renderable() {

}
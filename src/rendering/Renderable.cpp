#include "../../include/Renderable.h"
#include <cstddef>
#include <glm/detail/setup.hpp>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

std::vector<Renderable *> Renderable::_renderables;

Renderable::Renderable(
    float *vertices, size_t verticesSize,
    uint *indices, size_t indicesSize,
    vec3 position
) {
    this->_vertices = vertices;
    this->_verticesSize = verticesSize;
    this->_indices = indices;
    this->_indicesSize = indicesSize;
    this->_position = position;
    _renderables.push_back(this);
}

Renderable::Renderable(Shapes shape, vec3 position, vec3 color) {
    this->_position = position;

    if (shape == CUBE) {
        this->_vertices = new float[24]{
            position.x - 0.5f, position.y - 0.5f, position.y - 0.5f,
            position.x + 0.5f, position.y - 0.5f, position.y - 0.5f,
            position.x + 0.5f, position.y + 0.5f, position.y - 0.5f,
            position.x - 0.5f, position.y + 0.5f, position.y - 0.5f,
            position.x - 0.5f, position.y - 0.5f, position.y + 0.5f,
            position.x + 0.5f, position.y - 0.5f, position.y + 0.5f,
            position.x + 0.5f, position.y + 0.5f, position.y + 0.5f,
            position.x - 0.5f, position.y + 0.5f, position.y + 0.5f,
        };
        this->_verticesSize = 24;

        this->_indices = new unsigned int[36]{
            0, 1, 3, 1, 2, 3,
            4, 5, 7, 5, 6, 7,
            4, 5, 1, 4, 1, 0,
            3, 2, 6, 3, 6, 7,
            4, 0, 3, 4, 3, 7,
            1, 5, 6, 1, 6, 2
        };
        this->_indicesSize = 36;
    } else if (shape == SPHERE) {
        this->_vertices = new float[30]{
            0.0f, 1.0f, 0.0f,
            0.866f, 0.5f, 0.0f,
            0.433f, 0.5f, 0.75f,
            -0.433f, 0.5f, 0.75f,
            -0.866f, 0.5f, 0.0f,
            -0.433f, 0.5f, -0.75f,
            0.433f, 0.5f, -0.75f,
            0.866f, 0.5f, 0.0f,

            0.0f, -1.0f, 0.0f, 0.5f, 0.5f, 0.5f,
        };
        this->_verticesSize = 30;

        this->_indices = new unsigned int[42]{
            0, 1, 2,
            0, 2, 3,
            0, 3, 4,
            0, 4, 5,
            0, 5, 6,
            0, 6, 7,
            0, 7, 1,

            8, 2, 1,
            8, 3, 2,
            8, 4, 3,
            8, 5, 4,
            8, 6, 5,
            8, 7, 6,
            8, 1, 7,
        };
        this->_indicesSize = 42;
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderable::translate(vec3 direction) {
    _position += direction;

    for (size_t i = 0; i < _verticesSize; i += 3) {
        _vertices[i] += direction.x;
        _vertices[i + 1] += direction.y;
        _vertices[i + 2] += direction.z;
    }

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, _verticesSize * sizeof(float), _vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderable::rotate(float angle, vec3 axis) {
    // Create a rotation matrix
    mat4 rotationMatrix = glm::rotate(mat4(1.0f), radians(angle), axis);

    // Apply the rotation to each vertex
    for (size_t i = 0; i < _verticesSize; i += 3) {
        // Create a vec4 for the vertex (w = 1.0 for points)
        vec4 vertex(_vertices[i], _vertices[i + 1], _vertices[i + 2], 1.0f);

        // Apply the rotation
        vertex = rotationMatrix * vertex;

        // Update the vertex position
        _vertices[i] = vertex.x;
        _vertices[i + 1] = vertex.y;
        _vertices[i + 2] = vertex.z;
    }

    // Update the vertex buffer with the new data
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, _verticesSize * sizeof(float), _vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderable::setPosition(const vec3 position) {
    translate(-_position);
    translate(position);
}


void Renderable::render() const {
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

bool Renderable::isRenderingEnabled() const {
    return _renderingEnabled;
}

void Renderable::bindAll() {
    for (Renderable *renderable: _renderables) {
        renderable->bind();
    }
}

void Renderable::renderAll() {
    for (const Renderable *renderable: _renderables) {
        if (renderable->isRenderingEnabled()) {
            renderable->render();
        }
    }
}

Renderable::~Renderable() {
    if (_vertices != nullptr) {
        delete[] _vertices;
        _vertices = nullptr;
    }
    if (_indices != nullptr) {
        delete[] _indices;
        _indices = nullptr;
    }

    if (_VAO != 0) {
        glDeleteVertexArrays(1, &_VAO);
        _VAO = 0;
    }
    if (_VBO != 0) {
        glDeleteBuffers(1, &_VBO);
        _VBO = 0;
    }
    if (_EBO != 0) {
        glDeleteBuffers(1, &_EBO);
        _EBO = 0;
    }
}

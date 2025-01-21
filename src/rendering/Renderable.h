#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <demoShaderLoader.h>
#include <cstddef>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/detail/setup.hpp>

using namespace glm;

enum Shapes {
    CUBE = 0,
    SPHERE = 1,
    PLANE = 2,
    CYLINDER = 3,
    CONE = 4,
    PYRAMID = 5
};

class Renderable {
    static std::vector<Renderable> _renderables;

    float* _vertices;
    size_t _verticesSize;

    uint *_indices;
    size_t _indicesSize;

    Shader* _shader = nullptr;
    vec3 _position;

    uint  _VAO, _VBO, _EBO;
public:
    Renderable(float* vertices, size_t verticesSize, uint * indices, size_t indicesSize, vec3 position);
    Renderable(Shapes shape, vec3 position, vec3 color = vec3(1, 1, 1));

    void translate(vec3 direction);

    void bind();
    void render();

    static void renderAll();
    static void bindAll();

    ~Renderable();
};



#endif

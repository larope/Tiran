#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <demoShaderLoader.h>
#include <cstddef>
#include <vector>
#include <../thirdparty/glm/glm/vec3.hpp>
#include <../thirdparty/glm/glm/detail/setup.hpp>

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
    static std::vector<Renderable*> _renderables;

    float* _vertices;
    size_t _verticesSize;

    float* _verticesPositioned;

    uint *_indices;
    size_t _indicesSize;

    Shader* _shader = nullptr;
    vec3 _position;

    uint  _VAO, _VBO, _EBO;
    bool _renderingEnabled = true;
public:
    Renderable(float* vertices, size_t verticesSize, uint * indices, size_t indicesSize, vec3 position);
    Renderable(Shapes shape, vec3 position, vec3 color = vec3(1, 1, 1));

    void translate(vec3 direction);
    void rotate(float angle, vec3 axis);
    void setPosition(vec3 position);


    void bind();
    void render();

    void enableRendering();
    void disableRendering();

    bool isRenderingEnabled();

    static void renderAll();
    static void bindAll();

    ~Renderable();
};

#endif

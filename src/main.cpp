#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <openglDebug.h>
#include <demoShaderLoader.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "Rendering/Renderable.h"

using namespace glm;
using namespace std;


int main() {
#pragma region Window Initialization
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }
    cout << "GLFW is successfully initialized!" << endl;

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Cube", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        cerr << "Failed to create GLFW window" << endl;
        return -1;
    }
    glfwMakeContextCurrent(window);
    cout << "Window is successfully created!" << endl;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cerr << "Failed to initialize GLAD" << endl;
        return -1;
    }
    cout << "GLAD is successfully initialized!" << endl;
#pragma endregion
#pragma region Shader Initialization
    Shader defaultShader;
    defaultShader.loadShaderProgramFromFile(RESOURCES_PATH "vertex.vert", RESOURCES_PATH "fragment.frag");
    defaultShader.bind();

    int u_ViewLocation = defaultShader.getUniform("u_View");
    int u_ProjectionLocation = defaultShader.getUniform("u_Projection");

    mat4 view = translate(mat4(1.0f), vec3(0.0f, 0.0f, -3.0f));
    mat4 projection = perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    glUniformMatrix4fv(u_ViewLocation, 1, GL_FALSE, value_ptr(view));
    glUniformMatrix4fv(u_ProjectionLocation, 1, GL_FALSE, value_ptr(projection));

    glEnable(GL_DEPTH_TEST);
#pragma endregion

    Renderable cube(CUBE, vec3(0,0,0));
    Renderable cube1(CUBE, vec3(2,0,1));

    Renderable::bindAll();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        defaultShader.bind();
        view = translate(mat4(1.0f), vec3(0.0f, 0.0f,  -3.0f));

        glUniformMatrix4fv(u_ViewLocation, 1, GL_FALSE, value_ptr(view));

        Renderable::renderAll();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
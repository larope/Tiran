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

#include "InputManager.h"
#include "../include/Renderable.h"

using namespace glm;
using namespace std;

// MouseButtonInput mouseButtonInput;

int main() {
#pragma region Window Initialization
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }
    cout << "GLFW is successfully initialized!" << endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Cube", nullptr, nullptr);

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
    int u_TimeElapsed = defaultShader.getUniform("u_TimeElapsed");;
    mat4 view = translate(mat4(1.0f), vec3(0.0f, 0.0f, -3.0f));
    mat4 projection = perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    glUniformMatrix4fv(u_ViewLocation, 1, GL_FALSE, value_ptr(view));
    glUniformMatrix4fv(u_ProjectionLocation, 1, GL_FALSE, value_ptr(projection));

    glEnable(GL_DEPTH_TEST);
#pragma endregion
#pragma region Input Initialization
    InputManager::getInstance().setContext(window);
#pragma endregion
    Renderable cube(CUBE, vec3(1,0,0), vec3(0,1,1));
    Renderable cube1(CUBE, vec3(-1,0,0), vec3(1,1,1));
    Renderable cube2(CUBE, vec3(0.3,0,1), vec3(1,1,0));
    Renderable cube3(CUBE, vec3(0,1,0), vec3(1,0,0));
    Renderable cube4(CUBE, vec3(0.2,1,0), vec3(1,1,1));

    Renderable::bindAll();

    // glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
    //     mouseButtonInput.emit(window, button, action, mods);
    // });
    float t = 0;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        t += 0.01;
        glUniform1f(u_TimeElapsed, t);
        Renderable::renderAll();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
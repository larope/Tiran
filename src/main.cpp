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

#include "Entity.h"
#include "InputManager.h"
#include "../include/Renderable.h"
#include "game/Player.h"
#include "game/game.h"

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

mat4 view = translate(mat4(1.0f), vec3(0.0f, 0.0f, -3.0f));
mat4 projection = perspective(radians(90.0f), 800.0f / 600.0f, 0.1f, 100.0f);

glUniformMatrix4fv(u_ViewLocation, 1, GL_FALSE, value_ptr(view));
glUniformMatrix4fv(u_ProjectionLocation, 1, GL_FALSE, value_ptr(projection));

glEnable(GL_DEPTH_TEST);
#pragma endregion
#pragma region Input Initialization
InputManager::setContext(window);
#pragma endregion

    game::setup();
    Entity::setupAll();


    Renderable::bindAll();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        const auto now = static_cast<float>(glfwGetTime());

        Time::_currentTime = now;
        Time::_fps = 1.f / (now - Time::_timeElapsed);
        Time::_timeElapsed = now;

        game::loop();
        Entity::loopAll();

        Renderable::renderAll();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
#include "InputManager.h"

void InputManager::setContext(GLFWwindow *window) {
    _window = window;
    setCallbacks();
}

void InputManager::setCallbacks() {
    glfwSetKeyCallback(_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        _instance._keyboardInput.emit(window, key, scancode, action, mods);
    });
    glfwSetMouseButtonCallback(_window, [](GLFWwindow *window, int button, int action, int mods) {
        _instance._mouseButton.emit(window, button, action, mods);
    });
    glfwSetCursorPosCallback(_window, [](GLFWwindow *window, double x, double y) {
        _instance._mousePosition.emit(window, x, y);
    });
}


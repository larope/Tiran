#include "InputManager.h"

void InputManager::setContext(GLFWwindow *window) {
    _instance._window = window;
    _instance.setCallbacks();
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

void InputManager::addKeyboardInputListener(artt::Observer<GLFWwindow*, int, int, int, int>* listener) {
    _instance._keyboardInput.subscribe(listener);
}

void InputManager::addMouseButtonListener(artt::Observer<GLFWwindow *, int, int, int> *listener) {
    _instance._mouseButton.subscribe(listener);
}

void InputManager::addMousePositionListener(artt::Observer<GLFWwindow*, double, double>* listener){
    _instance._mousePosition.subscribe(listener);
}
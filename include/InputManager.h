#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "Dispatcher.h"
#include "KeyboardInput.h"
#include "MousePositionInput.h"
#include "MouseButtonInput.h"
#include "Singleton.h"

class InputManager : public artt::Singleton<InputManager>{
    friend class artt::Singleton<InputManager>;
    InputManager() = default;

    KeyboardInput _keyboardInput;
    MousePositionInput _mousePosition;
    MouseButtonInput _mouseButton;

    GLFWwindow* _window = nullptr;

    void setCallbacks();

public:
    void setContext(GLFWwindow *window);
    void addKeyboardInputListener();
};

#endif

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "../tools/Dispatcher.h"
#include "KeyboardInput.h"
#include "MousePositionInput.h"
#include "MouseButtonInput.h"

class InputManager {
    KeyboardInput _keyboardInput;
    MousePositionInput _mousePosition;
    MouseButtonInput _mouseButton;
public:
};

#endif

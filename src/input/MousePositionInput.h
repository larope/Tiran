#ifndef MOUSEPOSITIONINPUT_H
#define MOUSEPOSITIONINPUT_H

#include "GLFW/glfw3.h"
#include "../tools/Dispatcher.h"

class MousePositionInput : artt::Dispatcher<GLFWwindow*, double, double>{

};

#endif

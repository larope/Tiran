#ifndef MOUSEPOSITIONINPUT_H
#define MOUSEPOSITIONINPUT_H

#include "GLFW/glfw3.h"
#include "Dispatcher.h"

class MousePositionInput : public artt::Dispatcher<GLFWwindow*, double, double>{

};

#endif

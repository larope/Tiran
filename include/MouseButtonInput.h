#ifndef MOUSEINPUT_H
#define MOUSEINPUT_H

#include "GLFW/glfw3.h"
#include "Dispatcher.h"

class MouseButtonInput : public artt::Dispatcher<GLFWwindow*, int, int, int>{
public:
};

#endif
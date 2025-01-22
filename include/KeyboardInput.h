#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include <GLFW/glfw3.h>
#include "Dispatcher.h"

class KeyboardInput : public artt::Dispatcher<GLFWwindow*, int, int, int, int>{
};

#endif

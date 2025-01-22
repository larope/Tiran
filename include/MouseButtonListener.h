#ifndef MOUSEBUTTONLISTENER_H
#define MOUSEBUTTONLISTENER_H
#include "Observer.h"
#include "GLFW/glfw3.h"

class MouseButtonListener : protected artt::Observer<GLFWwindow*, int, int, int>{

};

#endif

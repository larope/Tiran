#ifndef MYGAME_MOUSEPOSITIONLISTENER_H
#define MYGAME_MOUSEPOSITIONLISTENER_H

#include "GLFW/glfw3.h"
#include "Observer.h"

class MousePositionListener : artt::Observer<GLFWwindow*, double, double>{

};

#endif

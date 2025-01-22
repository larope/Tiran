#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#include "Observer.h"
#include "GLFW/glfw3.h"

class KeyboardListener : protected artt::Observer<GLFWwindow*, int, int, int, int>{

};

#endif

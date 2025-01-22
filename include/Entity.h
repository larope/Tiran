#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include "MouseButtonListener.h"
#include "KeyboardListener.h"
#include "MousePositionListener.h"

class Entity : MouseButtonListener, KeyboardListener, MousePositionListener{
    friend int main();

    static void loopAll();
    static std::vector<Entity*> _entities;
protected:
    Entity();
    virtual void gameLoop() = 0;

    virtual void onKeyboardInput(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;
    virtual void onMouseButtonInput(GLFWwindow *window, int button, int action, int mods) = 0;
    virtual void onMousePositionChange(GLFWwindow* window, double x, double y) = 0;
public:
    ~Entity() override = default;

    void onNotify (GLFWwindow* window, double x, double y) override;
    void onNotify(GLFWwindow *window, int key, int scancode, int action, int mods) override;
    void onNotify(GLFWwindow *window, int button, int action, int mods) override;
};

#endif

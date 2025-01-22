#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include "MouseButtonListener.h"
#include "KeyboardListener.h"
#include "MousePositionListener.h"
#include "../src/game/game.h"

class Entity : public MouseButtonListener, public KeyboardListener, public MousePositionListener{
    friend int main();
    friend void game::setup();

    static void loopAll();
    static void setupAll();
    static std::vector<Entity*> _entities;
protected:
    Entity();
    virtual void gameLoop(){}
    virtual void setup(){}

    virtual void onKeyboardInput(GLFWwindow *window, int key, int scancode, int action, int mods){}
    virtual void onMouseButtonInput(GLFWwindow *window, int button, int action, int mods){}
    virtual void onMousePositionChange(GLFWwindow* window, double x, double y){}
public:
    ~Entity();

    void onNotify (GLFWwindow* window, double x, double y) override;
    void onNotify (GLFWwindow *window, int key, int scancode, int action, int mods) override;
    void onNotify (GLFWwindow *window, int button, int action, int mods) override;
};

#endif

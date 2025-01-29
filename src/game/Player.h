#ifndef PLAYER_H
#define PLAYER_H
#include "../../include/Entity.h"


class Player : public Entity{
public:
    Player();
    void gameLoop() override;
    void setup() override;
    void onKeyboardInput(GLFWwindow *window, int key, int scancode, int action, int mods) override;
};



#endif

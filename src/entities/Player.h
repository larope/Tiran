#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player : public Entity{
public:
    Player();
    void gameLoop() override;
    void shout();
};



#endif

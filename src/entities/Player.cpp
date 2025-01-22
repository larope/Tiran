#include "Player.h"

#include <iostream>

Player::Player() {

}

void Player::shout() {
    std::cout << "Player shout" << std::endl;
}

void Player::gameLoop(){
    std::cout << "Player gameLoop" << std::endl;
}

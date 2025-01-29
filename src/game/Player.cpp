#include "./Player.h"

#include <iostream>

Player::Player() {

}

void Player::gameLoop(){
}

void Player::setup() {
}

void Player::onKeyboardInput(GLFWwindow *window, int key, int scancode, int action, int mods) {
    std::cout << "Player onKeyboardInput" << std::endl;
}
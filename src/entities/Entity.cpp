#include "Entity.h"

#include <iostream>
#include <ostream>

#include "InputManager.h"

std::vector<Entity*> Entity::_entities;

Entity::Entity() {

    _entities.push_back(this);
    InputManager::addKeyboardInputListener(this);
    InputManager::addMouseButtonListener(this);
    InputManager::addMousePositionListener(this);

}

void Entity::loopAll() {
    for (Entity* entity: _entities) {
        entity->gameLoop();
    }
}
void Entity::setupAll() {
    for (Entity* entity: _entities) {
        entity->setup();
    }
}

void Entity::onNotify(GLFWwindow *window, int key, int scancode, int action, int mods) {
    onKeyboardInput(window, key, scancode, action, mods);
}
void Entity::onNotify(GLFWwindow* window, int button, int action, int mods) {
    onMouseButtonInput(window, button, action, mods);
}

Entity::~Entity() {
    _entities.erase(std::find(_entities.begin(), _entities.end(), this) - 1);
};

void Entity::onNotify(GLFWwindow* window, double x, double y) {
    onMousePositionChange(window, x, y);
}

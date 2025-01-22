#include "Entity.h"
#include "InputManager.h"

std::vector<Entity*> Entity::_entities;

Entity::Entity() {
    _entities.push_back(this);
    InputManager::getInstance();
}

void Entity::loopAll() {
    for (auto entity: _entities) {
        (*entity).gameLoop();
    }
}

void Entity::onNotify(GLFWwindow *window, int key, int scancode, int action, int mods) {
    onKeyboardInput(window, key, scancode, action, mods);
}
void Entity::onNotify(GLFWwindow* window, int button, int action, int mods) {
    onMouseButtonInput(window, button, action, mods);
}
void Entity::onNotify(GLFWwindow* window, double x, double y) {
    onMousePositionChange(window, x, y);
}
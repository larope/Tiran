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
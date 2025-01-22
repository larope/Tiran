#ifndef ENTITY_H
#define ENTITY_H
#include <vector>

class Entity {
    friend void main();

    static void loopAll();
    static std::vector<Entity*> _entities;
protected:
    Entity();
    virtual void gameLoop() = 0;

    virtual void onKeyboardInput() = 0;
    virtual void onMouseInput() = 0;
    virtual void onMousePositionChange() = 0;
public:
    virtual ~Entity() = default;
};

#endif

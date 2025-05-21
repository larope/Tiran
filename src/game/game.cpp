#include <glm/trigonometric.hpp>
#include <glm/vec3.hpp>
#include "Renderable.h"
#include "Player.h"
#include "Time.h"

using namespace glm;

namespace game {
    Renderable cube(CUBE, vec3(2,0,0), vec3(0,1,1));
    // Renderable cube1(CUBE, vec3(-1,0,0), vec3(1,1,1));
    // Renderable cube2(CUBE, vec3(0.3,0,1), vec3(1,1,0));
    // Renderable cube3(CUBE, vec3(0,1,0), vec3(1,.4,.4));
    // Renderable cube4(CUBE, vec3(0.2,1,0), vec3(1,1,1));
    void setup(){
        Player* player;
        player = new Player();
    }

    void loop() {
        cube.rotate(10*2*M_PI*Time::deltaTime(), vec3(0, 1, 0));
        cube.setPosition(vec3(0,1,0)*Time::currentTimeSin());
    }
}
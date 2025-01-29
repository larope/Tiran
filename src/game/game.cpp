#include <glm/trigonometric.hpp>
#include <glm/vec3.hpp>
#include "Renderable.h"
#include "Player.h"

using namespace glm;

namespace game {
    Renderable cube(SPHERE, vec3(1,0,0), vec3(0,1,1));
    // Renderable cube1(CUBE, vec3(-1,0,0), vec3(1,1,1));
    // Renderable cube2(CUBE, vec3(0.3,0,1), vec3(1,1,0));
    // Renderable cube3(CUBE, vec3(0,1,0), vec3(1,.4,.4));
    // Renderable cube4(CUBE, vec3(0.2,1,0), vec3(1,1,1));
    void setup(){
        Player* player;
        player = new Player();
    }
    float t = 0;
    void loop() {
        t+=0.1;
        cube.rotate(2*M_PI/10, vec3(0, 1, 0));
    }
}
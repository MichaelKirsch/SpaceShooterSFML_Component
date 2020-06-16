#include "LinearMover.h"

void LinearMover::update(float deltaTime) {
    owner->transform->addPosition(direction*deltaTime*speed);
}

void LinearMover::start(sf::Vector2f i_direction, float i_speed) {
    direction = i_direction;
    speed = i_speed;
}

LinearMover::LinearMover(Entity *owner) : Component(owner) {

}



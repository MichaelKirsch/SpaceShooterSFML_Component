#pragma once
#include "Component.h"
#include "Entity.h"

class LinearMover : public Component{
public:
    LinearMover(Entity* owner);
    void start(sf::Vector2f i_direction, float i_speed);
    void update(float deltaTime);
    sf::Vector2f direction;
    float speed;
};



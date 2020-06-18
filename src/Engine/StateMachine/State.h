#pragma once
#include "SFML/Graphics.hpp"

class State {
public:
    State(){};
    virtual void update(float deltaTime){};
    virtual void draw(sf::RenderWindow& window){};
    virtual void inputs(){};
};



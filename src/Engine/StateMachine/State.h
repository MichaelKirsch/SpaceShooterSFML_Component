#pragma once
#include "SFML/Graphics.hpp"

class Statemachine;

class State {
public:
    State(Statemachine* st): stm(st){};
    virtual void update(float deltaTime){};
    virtual void draw(sf::RenderWindow& window){};
    virtual void inputs(){};
    Statemachine* stm;
};



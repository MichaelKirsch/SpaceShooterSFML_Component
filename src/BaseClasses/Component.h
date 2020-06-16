#pragma once
#include "SFML/Graphics.hpp"

class Entity; // 1

class Component
{
public:
    Component(Entity* owner) : owner(owner){}

    virtual void awake() {};
    virtual void start() {};

    virtual void update(float deltaTime) {};
    virtual void lateUpdate(float deltaTime) {};
    virtual void draw(sf::RenderWindow& window) {};

    bool active = true;

protected:
    Entity* owner;
};
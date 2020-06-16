//
// Created by micha on 10.06.2020.
//

#include "Transform.h"

Transform::Transform(Entity *owner) : Component(owner) {
    position = {0.f,0.f};
}

const sf::Vector2f &Transform::getPosition() const {
    return position;
}

void Transform::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Transform::setPosition(sf::Vector2f pos) {
    position = pos;
}

void Transform::addPosition(float x, float y) {
    position.x += x;
    position.y += y;
}

void Transform::addPosition(sf::Vector2f pos) {
    position+=pos;
}

void Transform::setX(float x) {
    position.x = x;
}

void Transform::setY(float y) {
    position.y = y;
}

//
// Created by micha on 10.06.2020.
//

#include "KeyboardMover.h"

KeyboardMover::KeyboardMover(Entity *owner) : Component(owner) {

}

void KeyboardMover::update(float deltaTime) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        owner->transform->addPosition(speed,0.1f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        owner->transform->addPosition(-speed,0.1f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        owner->transform->addPosition(0.f,speed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        owner->transform->addPosition(0.f,-speed);
}

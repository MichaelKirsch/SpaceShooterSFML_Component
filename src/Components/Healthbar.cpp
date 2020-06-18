//
// Created by micha on 18.06.2020.
//

#include "Healthbar.h"
#include "Health.h"

Healthbar::Healthbar(Entity *owner) : Component(owner) {

}

void Healthbar::start() {
    body.setSize({10,10});
    body.setFillColor(sf::Color::Red);
}

void Healthbar::update(float deltaTime) {
    body.setPosition(owner->transform->getPosition());
}

void Healthbar::draw(sf::RenderWindow &window) {
    if(active)
    {
        window.draw(body);
    }
}



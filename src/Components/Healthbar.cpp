//
// Created by micha on 18.06.2020.
//

#include "Healthbar.h"

Healthbar::Healthbar(Entity *owner) : Component(owner) {

}

void Healthbar::start() {
    foreground.setSize({10,10});
    foreground.setFillColor(sf::Color::Red);

    sizeOfOwner = owner->GetComponent<SimpleSprite>()->getSize();
    background.setSize({sizeOfOwner.x, 10});
    background.setFillColor(sf::Color::White);
}

void Healthbar::update(float deltaTime) {
    foreground.setPosition(owner->transform->getPosition());
    background.setPosition(owner->transform->getPosition());

    actualHealthRaw = owner->GetComponent<Health>()->getHealthRaw();

    if(actualHealthPercent >= 0)
        foreground.setSize({float(actualHealthPercent), 10});

}

void Healthbar::draw(sf::RenderWindow &window) {
    if(active){
        window.draw(background);
        window.draw(foreground);
    }


}

void Healthbar::setColor(sf::Color color) {
    m_color = color;
}

sf::Color Healthbar::getColor() {
    return m_color;
}



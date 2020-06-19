//
// Created by micha on 18.06.2020.
//

#include "Healthbar.h"

Healthbar::Healthbar(Entity *owner) : Component(owner) {

}

void Healthbar::start() {

    setColorForeground(sf::Color::Red);
    foreground.setSize({10,10});


    ownerHealth = owner->GetComponent<Health>();
    sizeOfOwner = owner->GetComponent<SimpleSprite>()->getSize();
    setColorBackground(sf::Color::White);
    background.setSize({sizeOfOwner.x, 10});
}

void Healthbar::update(float deltaTime) {
    foreground.setPosition(owner->transform->getPosition().x, owner->transform->getY() - 2*foreground.getSize().y );
    background.setPosition(owner->transform->getPosition().x, owner->transform->getY() - 2*foreground.getSize().y);

    actualHealthPercent = ownerHealth->getHealthPercent();
    if(actualHealthPercent >= 0)
        foreground.setSize({float(actualHealthPercent)*background.getSize().x, 10});

}

void Healthbar::draw(sf::RenderWindow &window) {
    if(active){
        window.draw(background);
        window.draw(foreground);
    }
}

void Healthbar::setColorForeground(sf::Color color) {
    m_colorForeground = color;
    foreground.setFillColor(m_colorForeground);
}

void Healthbar::setColorBackground(sf::Color color) {
    m_colorBackground = color;
    background.setFillColor(m_colorBackground);
}

sf::Color Healthbar::getColorForeground() {
    return m_colorForeground;
}

sf::Color Healthbar::getColorBackground() {
    return m_colorBackground;
}





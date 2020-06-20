//
// Created by thewh on 6/20/2020.
//

#include "EnergyCore.h"



EnergyCore::EnergyCore(Entity *owner) : Component(owner) {}

void EnergyCore::start()
{
    active = true;
    ownerHealth = owner->GetComponent<Health>();
    sizeOfOwner = owner->GetComponent<SimpleSprite>()->getSize();
    m_texture.loadFromFile("data/Core2.png");

    m_core.setSize({0.25f * sizeOfOwner.x, 0.25f * sizeOfOwner.y});
    m_core.setPosition({sizeOfOwner.x / 2 - m_core.getSize().x / 2, 0.5f * sizeOfOwner.y});
    m_core.setTexture(&m_texture);
    setColorForeground(sf::Color(0, 220, 0, 255));
    foreground.setRadius(m_core.getSize().x / 2);
}

void EnergyCore::setColorForeground(sf::Color color) {
    m_colorForeground = color;
    foreground.setFillColor(m_colorForeground);
}

void EnergyCore::update(float deltaTime) {
    actualHealthPercent = ownerHealth->getHealthPercent();
    actualHealthRaw = ownerHealth->getHealthRaw();
    if(actualHealthPercent==0)
        active = false;
    foreground.setPosition({owner->transform->getPosition().x + sizeOfOwner.x / 2 - foreground.getRadius(), owner->transform->getY() + (0.5f*sizeOfOwner.y)});
    actualHealthPercent = ownerHealth->getHealthPercent();
    actualHealthRaw = ownerHealth->getHealthRaw();
    setColorForeground({0, 220, 0, sf::Uint8(255*(ownerHealth->getHealthPercent()*0.01f))});
    m_core.setPosition({owner->transform->getPosition().x + sizeOfOwner.x / 2 - foreground.getRadius(), owner->transform->getY() + (0.5f*sizeOfOwner.y)});
}

void EnergyCore::draw(sf::RenderWindow &window) {
    if(active){
        window.draw(m_core);
        window.draw(foreground);
    }
}

void EnergyCore::lateUpdate(float deltaTime) {}

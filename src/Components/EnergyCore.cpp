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
    m_core = owner->AddComponent<SimpleSprite>();
    m_core->setSize({0.25f * sizeOfOwner.x, 0.25f * sizeOfOwner.y});
    m_core->load("data/Core.png");
    m_core->setOffset({sizeOfOwner.x / 2, 0.7f * sizeOfOwner.y});
    setColorForeground(sf::Color(0, 220, 0, 255));
    foreground.setRadius( m_core->getSize().x / 2);
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
    foreground.setPosition(owner->transform->getPosition().x + sizeOfOwner.x / 2, owner->transform->getY() - (0.6f*m_core->getSize().y));
    actualHealthPercent = ownerHealth->getHealthPercent();
    actualHealthRaw = ownerHealth->getHealthRaw();
    setColorForeground({0, 220, 0, sf::Uint8(255-(actualHealthPercent * 255))});
    m_core->update(deltaTime);
}

void EnergyCore::draw(sf::RenderWindow &window) {
    if(active){
        m_core->draw(window);
        window.draw(foreground);
    }
}

void EnergyCore::lateUpdate(float deltaTime) {}

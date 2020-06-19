//
// Created by micha on 19.06.2020.
//

#include "Aura.h"

Aura::Aura(Entity *owner) : Component(owner) {

}

void Aura::start() {
    sprite_of_owner = owner->GetComponent<SimpleSprite>();
    auraInner.setRadius(sprite_of_owner->getSize().x*0.3f);
    auraOuter.setRadius(sprite_of_owner.get()->getSize().x*0.5f);
    innerAlpha = 100;
    outerAlpha = 150;
    auraOuter.setFillColor({20, 142, 255,sf::Uint8 (innerAlpha)});
    auraInner.setFillColor({20, 204, 255,sf::Uint8 (outerAlpha)});
    auraInner.setOrigin(auraInner.getRadius(),auraInner.getRadius());
    auraOuter.setOrigin(auraOuter.getRadius(),auraOuter.getRadius());
}

void Aura::update(float deltaTime) {
    sf::Vector2f middleowner = {sprite_of_owner->getSize().x/2.f,sprite_of_owner->getSize().y/2.f};
    auraInner.setPosition(owner->transform->getPosition()+middleowner);
    auraOuter.setPosition(owner->transform->getPosition()+middleowner);
    outerAlpha+=1.1f;
    if(outerAlpha>100.f)
        outerAlpha=0.f;
    innerAlpha+=1.1f;
    if(innerAlpha>150.f)
        innerAlpha=0.f;

    sf::Color ioriginalCol = auraInner.getFillColor();
    sf::Color ooriginalCol = auraOuter.getFillColor();
    ioriginalCol.a = innerAlpha;
    ooriginalCol.a = outerAlpha;
    auraOuter.setFillColor(ooriginalCol);
    auraInner.setFillColor(ioriginalCol);
}

void Aura::draw(sf::RenderWindow &window) {
    if(active)
    {
        window.draw(auraOuter);
        window.draw(auraInner);
    }
}

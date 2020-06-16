//
// Created by micha on 16.06.2020.
//

#include "Hitbox.h"

Hitbox::Hitbox(Entity *owner) : Component(owner) {
}

void Hitbox::update(float deltaTime) {
    hitbox.setPosition(owner->transform->getPosition()+m_offset_Center_Owner);
}

void Hitbox::start(sf::Vector2f size, sf::Vector2f i_offset_Center_Owner) {
    hitbox.setSize(size);
    m_offset_Center_Owner = i_offset_Center_Owner;
    hitbox.setPosition(owner->transform->getPosition()+m_offset_Center_Owner);
}

bool Hitbox::AABBCollisionTest(Hitbox &otherBox) {
    return hitbox.getGlobalBounds().intersects(otherBox.hitbox.getGlobalBounds());
}

bool Hitbox::AABBCollisionTest(std::shared_ptr<Hitbox> otherBox) {
    return hitbox.getGlobalBounds().intersects(otherBox->hitbox.getGlobalBounds());
}


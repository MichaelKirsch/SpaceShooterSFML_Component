//
// Created by micha on 18.06.2020.
//

#include "Animation.h"

Animation::Animation(Entity *owner) : Component(owner) {

}

void Animation::start() {
    sprite = owner->GetComponent<SimpleSprite>();
}

void Animation::update(float deltaTime) {
}

void Animation::draw(sf::RenderWindow &window) {
}

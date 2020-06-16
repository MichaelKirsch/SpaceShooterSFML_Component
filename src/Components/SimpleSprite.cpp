//
// Created by micha on 10.06.2020.
//

#include "SimpleSprite.h"

void SimpleSprite::load(const std::string &filePath) {
    texture.loadFromFile(filePath);
    sprite.setTexture(&texture);
}

void SimpleSprite::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

SimpleSprite::SimpleSprite(Entity *owner) : Component(owner) {

}

void SimpleSprite::lateUpdate(float deltaTime) {
    sprite.setPosition(owner->transform->getPosition());
}

void SimpleSprite::update(float deltaTime) {
    sprite.setPosition(owner->transform->getPosition());
}

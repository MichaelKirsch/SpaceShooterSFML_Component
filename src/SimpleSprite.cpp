//
// Created by micha on 10.06.2020.
//

#include "SimpleSprite.h"

void SimpleSprite::load(const std::string &filePath) {
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
    sprite.scale(0.3f,0.3f);
}

void SimpleSprite::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

SimpleSprite::SimpleSprite(Entity *owner) : Component(owner) {

}

void SimpleSprite::lateUpdate(float deltaTime) {
    sprite.setPosition(owner->transform->getPosition());
}

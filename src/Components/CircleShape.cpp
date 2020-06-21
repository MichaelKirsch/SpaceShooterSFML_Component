//
// Created by Dennis on 20/06/2020.
//

#include "CircleShape.h"

void CircleShape::draw(sf::RenderWindow &window) {
   window.draw(m_circle);
}

void CircleShape::setSize(float i_size) {
    m_circle.setRadius(i_size);
}

float CircleShape::getSize() {
    return m_circle.getRadius();
}

void CircleShape::load(const std::string &filePath) {
    m_texture.loadFromFile(filePath);
    m_circle.setTexture(&m_texture);
}

sf::Texture &CircleShape::getTexture() {
    return m_texture;
}

CircleShape::CircleShape(Entity *owner) : Component(owner) {

}

void CircleShape::setOffset(sf::Vector2f offsetToOwner) {
    m_offset = offsetToOwner;
}

sf::Vector2f CircleShape::getOffset() {
    return m_offset;
}

void CircleShape::update(float deltaTime) {
    m_circle.setPosition(owner->transform->getPosition()+m_offset);
}

void CircleShape::lateUpdate(float deltaTime) {
    m_circle.setPosition(owner->transform->getPosition()+m_offset);
}

sf::CircleShape &CircleShape::getCircle() {
    return m_circle;
}



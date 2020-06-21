//
// Created by Dennis on 20/06/2020.
//

#pragma once
#include "Component.h"
#include "Entity.h"


class CircleShape: public Component {
public:

    CircleShape(Entity* owner);
    void load(const std::string &filePath);
    void setSize(float i_size);
    float getSize();

    sf::Texture &getTexture();
    sf::CircleShape& getCircle();

    void draw(sf::RenderWindow &window) override;

    void lateUpdate(float deltaTime) override;

    void update(float deltaTime) override;

    void setOffset(sf::Vector2f offsetToOwner);
    sf::Vector2f getOffset();

private:
    sf::CircleShape m_circle;
    sf::Texture m_texture;
    sf::Vector2f m_offset = {0.f, 0.f};




};





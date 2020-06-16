#pragma once
#include "Component.h"
#include "Entity.h"

class Hitbox : public Component{
public:
    Hitbox(Entity* owner);

    void start(sf::Vector2f size, sf::Vector2f offset_Center_Owner={0.f,0.f});

    void update(float deltaTime) override;

    bool AABBCollisionTest(Hitbox& otherBox);
    bool AABBCollisionTest(std::shared_ptr<Hitbox> otherBox);
    sf::RectangleShape hitbox;
    sf::Vector2f m_offset_Center_Owner;
};



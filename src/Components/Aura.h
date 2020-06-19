#pragma once
#include "Component.h"
#include "Entity.h"
#include "SimpleSprite.h"

class Aura : public Component{
public:
    Aura(Entity* owner);

    void start() override;

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;


private:
    std::shared_ptr<SimpleSprite> sprite_of_owner;
    sf::CircleShape auraOuter;
    sf::CircleShape auraInner;
    float innerAlpha,outerAlpha;
};



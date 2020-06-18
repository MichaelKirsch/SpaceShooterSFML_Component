#pragma once
#include "Component.h"
#include "Entity.h"
#include "SimpleSprite.h"

class Animation : public Component{
public:
    Animation(Entity* owner);

    void start() override;

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

private:
    std::shared_ptr<SimpleSprite> sprite;
    sf::Texture* textPtrSprite;
};



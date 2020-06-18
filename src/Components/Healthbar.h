#pragma once
#include "Component.h"
#include "Entity.h"

class Healthbar : public Component{
public:
    Healthbar(Entity* owner);

    void start() override;

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

private:
    sf::RectangleShape body;
};



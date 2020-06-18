#pragma once
#include "Component.h"
#include "Entity.h"
#include "SimpleSprite.h"

#include "Health.h"


class Healthbar : public Component{
public:
    Healthbar(Entity* owner);

    void start() override;

    void update(float deltaTime) override;
    void setColor(sf::Color color);
    sf::Color getColor();

    void draw(sf::RenderWindow &window) override;

private:
    sf::RectangleShape foreground;
    sf::RectangleShape background;

    sf::Color m_color;
    int actualHealthPercent;
    sf::Vector2f sizeOfOwner;
    float actualHealthRaw;
};



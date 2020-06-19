#pragma once
#include "Component.h"
#include "Entity.h"
#include "SimpleSprite.h"

#include "Health.h"


class Healthbar : public Component{
public:
    Healthbar(Entity* owner);

    void start(sf::Color backgroundColor = {255, 255, 255}, sf::Color foregroundColor = {239, 87, 78});

    void update(float deltaTime) override;

    void setColorForeground(sf::Color color);
    void setColorBackground(sf::Color color);

    sf::Color& getColorForeground();
    sf::Color& getColorBackground();


    void draw(sf::RenderWindow &window) override;

private:
    sf::RectangleShape foreground;
    sf::RectangleShape background;

    std::shared_ptr<Health> ownerHealth;

    sf::Color m_colorForeground;
    sf::Color m_colorBackground;

    int actualHealthPercent;
    sf::Vector2f sizeOfOwner;
    float actualHealthRaw;
};



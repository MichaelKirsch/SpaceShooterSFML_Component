#pragma once
#include "Entity.h"
#include "MouseOver.h"
#include "SimpleSprite.h"
#include "Text.h"

class Button : public Entity{
public:
    Button();

    void start(sf::RenderWindow& window,sf::Vector2f pos, sf::Vector2f size,std::string font, std::string background,std::string buttonText);

    void update(float deltaTime);

    void draw(sf::RenderWindow &window) override;

    std::shared_ptr<MouseOver> mouse;

    void setTextColor(sf::Color newCol)
    {
        text->setColor(newCol);
    }

    void setTextToMax();

    void setText(std::string text);
private:
    std::shared_ptr<SimpleSprite> body;

    std::shared_ptr<Text> text;
};



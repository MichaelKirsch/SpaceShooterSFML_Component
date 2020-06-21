#pragma once
#include "Component.h"
#include "Entity.h"

class Text : public Component{
public:
    Text(Entity* owner);

    void start(float text_size, std::string i_text, std::string font_path,sf::Color text_color);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    sf::Vector2f offset={0.f,0.f};

    void setText(std::string new_text);

    sf::Color& getColor(){return fillcolor;};

    void setColor(sf::Color new_color);

    void setTextsize(float new_textsize);
private:
    sf::Text text;
    sf::Font font;
    sf::Color fillcolor;
};



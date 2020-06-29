//
// Created by micha on 28.06.2020.
//

#include "Button.h"

void Button::update(float deltaTime) {
    Entity::update(deltaTime);
    if(text->getTextsize()<body->getSize().y)
    {
        int height = text->getTextsize();
        int heightbody = body->getSize().y;
       float offset = ((heightbody-height)/2.f);
       text->offset = {0.f,offset};
    }
}

void Button::start(sf::RenderWindow& window,sf::Vector2f pos, sf::Vector2f size, std::string font_path, std::string background, std::string buttonText) {
    transform->setPosition(pos);
    body->start();
    body->load(background);
    body->setSize(size);
    text->start(body->getSize().y,buttonText,font_path,sf::Color::White);
    mouse->start(window);
    setText(buttonText);
}

Button::Button() {
    body = AddComponent<SimpleSprite>();
    mouse = AddComponent<MouseOver>();
    text = AddComponent<Text>();
}

void Button::setText(std::string i_text) {
    text->setText(i_text);
    auto outline = body->getSize();
    while (text->getGlobalBounds().width>outline.x)
        text->setTextsize(text->getTextsize()*0.95);

}

void Button::draw(sf::RenderWindow &window) {
    Entity::draw(window);
    text->draw(window);
}

void Button::setTextToMax() {
    auto outline = body->getSize();
    while(text->getGlobalBounds().width<outline.x)
    {
        text->setTextsize(text->getTextsize()*1.1f);
    }
}




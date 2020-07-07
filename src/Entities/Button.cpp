//
// Created by micha on 28.06.2020.
//

#include "Button.h"

void Button::update(float deltaTime) {
    Entity::update(deltaTime);
    if(text->getGlobalBounds().height<body->getSize().y)
    {
        float height = text->getGlobalBounds().height;
        float heightbody = body->getSize().y;
       float offset = heightbody/2.f-height;
       text->offset.y = offset;
    }
    if(text->getGlobalBounds().width<body->getSize().x)
    {
        text->offset.x = 0.5f*(body->getSize().x-text->getGlobalBounds().width);
    }

    timer+=deltaTime;
    if(mouse->clickedLeft&&timer>debouncetime)
    {
        leftClicked_t = true;
        timer=0.f;
    } else
        leftClicked_t = false;

    if(mouse->clickedRight&&timer>debouncetime)
    {
        rightClicked_t = true;
        timer=0.f;
    } else
        rightClicked_t = false;

    hover = mouse->mouseOver;

    if(colorLoader!= nullptr)
    {
        if(hover&&change_on_hover)
        {
            body->getRect().setFillColor(colorLoader->getColor(color_loader::background2));
            text->setColor(colorLoader->getColor(color_loader::texthighlight));
        } else
        {
            body->getRect().setFillColor(colorLoader->getColor(color_loader::background));
            text->setColor(colorLoader->getColor(color_loader::text));
        }
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

void Button::setColorLoader(color_loader *loader) {
    colorLoader = loader;
    body->getRect().setFillColor(loader->getColor(loader->background));
    text->setColor(loader->getColor(loader->text));
}

void
Button::start(sf::RenderWindow &window, color_loader *loader, sf::Vector2f pos, sf::Vector2f size, std::string font,
              std::string background, std::string buttonText) {
    start(window,pos,size,font,background,buttonText);
    colorLoader = loader;
}




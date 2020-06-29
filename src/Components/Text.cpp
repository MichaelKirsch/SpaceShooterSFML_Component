//
// Created by micha on 21.06.2020.
//

#include "Text.h"

Text::Text(Entity *owner) : Component(owner) {

}


void Text::update(float deltaTime) {
    text.setFillColor(fillcolor);
    text.setPosition(owner->transform->getPosition()+offset);
}

void Text::draw(sf::RenderWindow &window) {
    window.draw(text);
}

void Text::start(float text_size, std::string i_text, std::string font_path, sf::Color text_color) {
    font.loadFromFile(font_path);
    text.setString(i_text);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setFillColor(text_color);
    fillcolor = text_color;
}

void Text::setText(std::string new_text) {
    text.setString(new_text);
}

void Text::setTextsize(float new_textsize) {
    text.setCharacterSize(new_textsize);
}

void Text::setColor(sf::Color new_color) {
    text.setFillColor(new_color);
    fillcolor = new_color;

}

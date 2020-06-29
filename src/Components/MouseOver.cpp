//
// Created by micha on 28.06.2020.
//

#include "MouseOver.h"

MouseOver::MouseOver(Entity *owner) : Component(owner) {

}

void MouseOver::update(float deltaTime) {
    auto body = spritebody->getRect();
    auto mouse_pos = sf::Mouse::getPosition(*window);
    if(body.getGlobalBounds().contains(mouse_pos.x,mouse_pos.y))
    {
        time_since_last_mouseover = 0.f;
        time_mouse_is_over +=deltaTime;
        mouseOver = true;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            clickedLeft = true;
            time_since_button_is_hold_left +=deltaTime;
        } else
        {
            clickedLeft = false;
            time_since_button_is_hold_left =0.f;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            clickedRight = true;
            time_since_button_is_hold_right +=deltaTime;
        } else
        {
            clickedRight = false;
            time_since_button_is_hold_right =0.f;
        }
    } else
    {
        time_since_last_mouseover+=0.f;
        mouseOver=false;
        time_mouse_is_over =0.f;
        time_since_button_is_hold_left=0.f;
        time_since_button_is_hold_right =0.f;
    }
}

void MouseOver::start(sf::RenderWindow &i_window) {
    spritebody =owner->GetComponent<SimpleSprite>();
    window = &i_window;
}





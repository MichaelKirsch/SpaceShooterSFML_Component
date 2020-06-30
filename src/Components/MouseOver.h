#pragma once
#include "Component.h"
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "SimpleSprite.h"

class MouseOver :public Component {
public:
    MouseOver(Entity* owner);

    void start(sf::RenderWindow& window);
    void update(float deltaTime);

    bool mouseOver=false;
    bool clickedLeft=false;
    bool clickedRight=false;
    float time_since_last_mouseover=0.f;
    float time_since_button_is_hold_left=0.f;
    float time_since_button_is_hold_right=0.f;
    float time_mouse_is_over=0.f;
    float time_since_last_click=0.f;
private:
    std::shared_ptr<SimpleSprite> spritebody;
    sf::RenderWindow* window;
};



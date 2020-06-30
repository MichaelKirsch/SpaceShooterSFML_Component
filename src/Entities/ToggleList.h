#pragma once
#include "Entity.h"
#include "Button.h"
#include <vector>
#include <iostream>

class ToggleList : public Entity{
public:
    ToggleList(){};

    void start(sf::RenderWindow& window,sf::Vector2f pos,sf::Vector2f size, std::string buttonleft, std::string buttonright,std::string texturemiddle, std::string font) {
        Entity::start();
        transform->setPosition(pos);
        m_window = &window;
        trueSize.x = size.x;
        trueSize.y = size.y;
        left.start(window,transform->getPosition(),{trueSize.x*0.25f,trueSize.y},font,buttonleft,"");
        right.start(window,{transform->getX()+(0.75f*trueSize.x),transform->getY()},{trueSize.x*0.25f,trueSize.y},font,buttonright,"");
        middle.start(window,{transform->getX()+(0.25f*trueSize.x),transform->getY()},{trueSize.x*0.5f,trueSize.y},font,texturemiddle,"100%");
        entities.push_back(&left);
        entities.push_back(&right);
        entities.push_back(&middle);
    }

    void update(float deltaTime) override {
        Entity::update(deltaTime);
        left.update(deltaTime);
        right.update(deltaTime);
        middle.update(deltaTime);
        left.transform->setPosition(transform->getPosition());
        right.transform->setPosition(transform->getX()+(0.75f*trueSize.x),transform->getY());
        middle.transform->setPosition({transform->getX()+(0.25f*trueSize.x),transform->getY()});
        if(left.hover)
        {
            left.setTextColor(sf::Color::Green);
            if(left.leftClicked_t)
            {
                left.setTextColor(sf::Color::Blue);
                iterator--;
                if(iterator<0)
                    iterator=0;
            }

        } else
            left.setTextColor(sf::Color::White);

        if(right.hover)
        {
            right.setTextColor(sf::Color::Green);
            if(right.leftClicked_t)
            {
                right.setTextColor(sf::Color::Blue);
                iterator++;
                if(iterator>values.size()-1)
                    iterator=values.size()-1;
            }

        } else
            right.setTextColor(sf::Color::White);
        if(!values.empty())
            middle.setText(values[iterator]);
    }

    void draw(sf::RenderWindow &window) override {
        Entity::draw(window);
        left.draw(window);
        right.draw(window);
        middle.draw(window);
    }

    void insertValue(std::vector<std::string> insertc){
        for(auto& c:insertc)
            values.emplace_back(c);
    }

    std::string getCurrentValue()
    {
        return values[iterator];
    }

    int getCurrentItemNbr()
    {
        return iterator;
    }


private:
    Button left, right,middle;
    std::vector<std::string> values;
    std::vector<Entity*> entities;
    sf::Vector2f trueSize={0.f,0.f};
    sf::RenderWindow* m_window;
    int iterator=0;
};


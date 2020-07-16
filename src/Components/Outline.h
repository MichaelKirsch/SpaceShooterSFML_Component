#pragma once
#include "Component.h"
#include "Entity.h"
//nearly every object will have this component. its a simple outline that will show how big the element is;
//in combination with the transform its very usefull;

class Outline : public Component{
public:
    Outline(Entity* owner);

    void setWidth(float width);

    void setHeight(float height);

    void setSize(float width, float height);

    void setSize(sf::Vector2f size);

    float getHeight();

    float getWidth();

private:
    sf::RectangleShape m_outline;
};



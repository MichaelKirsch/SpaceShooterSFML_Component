#pragma once
#include "Component.h"

class Transform : public Component{
public:
    Transform(Entity* owner);
    void setPosition(float x,float y);
    void setPosition(sf::Vector2f pos);

    void addPosition(float x, float y);
    void addPosition(sf::Vector2f pos);

    void setX(float x);
    void setY(float y);

    float getX(){return position.x;};
    float getY(){return position.y;};

    const sf::Vector2f& getPosition() const;

private:
    sf::Vector2f position;
};



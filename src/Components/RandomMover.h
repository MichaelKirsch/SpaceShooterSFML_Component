#pragma once
#include "Component.h"
#include "Entity.h"
#include <iostream>

class RandomMover : public Component{
public:
    RandomMover(Entity* owner);

    void setTimeBetweenBounce(float i_time);

    void setBoundaries(float i_x_min, float i_x_max, float i_y_min, float i_y_max);

    void update(float deltaTime) override;

private:
    float x_min,x_max, y_min, y_max, time,elapsed;
};



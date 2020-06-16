//
// Created by micha on 10.06.2020.
//

#include "RandomMover.h"

RandomMover::RandomMover(Entity *owner) : Component(owner) {
    x_max = 0.f;
    x_min = 0.f;
    time =0.f;
    y_min = 0.f;
    y_max = 0.f;
    elapsed =0.f;
}

void RandomMover::update(float deltaTime) {
    elapsed+=deltaTime;
    if(elapsed>time)
    {
        elapsed=0.f;

        auto oldpos = owner->transform->getPosition();

        float new_pos_x = x_min+rand()%(int)x_max;
        float new_pos_y = y_min+rand()%(int)y_max;
        owner->transform->addPosition(new_pos_x,new_pos_y);
    }
}


void RandomMover::setTimeBetweenBounce(float i_time) {
    time = i_time;
}

void RandomMover::setBoundaries(float i_x_min, float i_x_max, float i_y_min, float i_y_max) {
    x_max=i_x_max;
    x_min = i_x_min;
    y_min = i_y_min;
    y_max = i_y_max;
}

//
// Created by micha on 19.06.2020.
//

#include "InvisibiltyMode.h"

InvisibiltyMode::InvisibiltyMode(Entity *owner) : Component(owner) {

}

void InvisibiltyMode::start(float timer) {
    max_Time = timer;
    ownerAura = owner->GetComponent<Aura>();
}

void InvisibiltyMode::update(float deltaTime) {
    timer-=deltaTime;
    if(timer<=0.f)
    {
        timer=0.f;
        ownerAura->active = false;
    } else
    {
        ownerAura->active = true;
    }
}

void InvisibiltyMode::trigger() {
    timer = max_Time;
}

bool InvisibiltyMode::isInvisible() {
    return timer>0.f;
}

void InvisibiltyMode::addTime(float time) {
    timer+=time;
}

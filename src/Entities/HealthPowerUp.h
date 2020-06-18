#pragma once
#include "Entity.h"
#include "SimpleSprite.h"
#include "Hitbox.h"
#include "LinearMover.h"

class HealthPowerUp : public Entity{
public:
    HealthPowerUp(){
        mover = AddComponent<LinearMover>();
        sprite = AddComponent<SimpleSprite>();
        hitbox = AddComponent<Hitbox>();
        sprite->load("data/health.PNG");
        sprite->setSize({25,25});
        hitbox->start(sprite->getSize());
        mover->start({0.f,1.f},10);
    };

    std::shared_ptr<SimpleSprite> sprite;
    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<LinearMover> mover;
private:
};



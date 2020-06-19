#pragma once
#include "Entity.h"
#include "SimpleSprite.h"
#include "Hitbox.h"
#include "LinearMover.h"

class InvisibleToken : public Entity {
public:
    InvisibleToken(){
        mover = AddComponent<LinearMover>();
        sprite = AddComponent<SimpleSprite>();
        hitbox = AddComponent<Hitbox>();
        sprite->load("data/invisible_icon.png");
        sprite->setSize({25,25});
        hitbox->start(sprite->getSize());
        mover->start({0.f,1.f},20);
    };

    std::shared_ptr<SimpleSprite> sprite;
    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<LinearMover> mover;
};



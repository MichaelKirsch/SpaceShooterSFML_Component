#pragma once
#include "Entity.h"
#include "SimpleSprite.h"
#include "Hitbox.h"
#include "LinearMover.h"

class PowerUp : public Entity{
public:
    PowerUp(){
        mover = AddComponent<LinearMover>();
        sprite = AddComponent<SimpleSprite>();
        hitbox = AddComponent<Hitbox>();
    };

    void start(std::string icon,sf::Vector2f size,float speed)
    {
        sprite->load(icon);
        sprite->setSize(size);
        hitbox->start(sprite->getSize());
        mover->start({0.f,1.f},speed);
    }
    std::shared_ptr<SimpleSprite> sprite;
    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<LinearMover> mover;
};



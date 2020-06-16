#pragma once
#include "Entity.h"
#include "SimpleSprite.h"
#include "Hitbox.h"
#include "ParticleEffect.h"
#include "LinearMover.h"

class Enemy : public Entity {
public:
    Enemy(){
        body = AddComponent<SimpleSprite>();
        body->setSize({100.f,100.f});
        body->load("data/a10000.png");
        mover = AddComponent<LinearMover>();
        mover->start({0.f,1.f},50.f);
        hitbox = AddComponent<Hitbox>();
        hitbox->start(body->getSize());
        particles = AddComponent<ParticleEffect>();
        particles->start(10,{255, 15, 15},{255, 36, 242},4.f,1.f);
        particles->gravity_direction={0.f,0.f};
        particles->offset = body->getSize()/2.f;
    };
    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<ParticleEffect> particles;
    std::shared_ptr<SimpleSprite> body;
    std::shared_ptr<LinearMover> mover;
private:
};



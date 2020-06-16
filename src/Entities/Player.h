#pragma once
#include "Entity.h"
#include "SimpleSprite.h"
#include "RandomMover.h"
#include "KeyboardMover.h"
#include "ParticleEffect.h"
#include "Hitbox.h"

class Player : public Entity{
public:
    Player(){
        sprite = AddComponent<SimpleSprite>();
        sprite->setSize({100,100});
        sprite->load("data/pngwave.png");
        mover = AddComponent<RandomMover>();
        mover->setTimeBetweenBounce(0.5f);
        mover->setBoundaries(0.f,100.f,0.1f,100.f);
        key = AddComponent<KeyboardMover>();
        effect = AddComponent<ParticleEffect>();

        effect->start(1000,{250, 130, 0},{250, 25, 0},3.f,2.f);
        effect->gravity_direction = {0.f,-1.f};
        effect2 = AddComponent<ParticleEffect>();
        effect2->start(100,{196, 196, 196},{196, 196, 196},3.f,2.f);
        effect2->gravity_direction = {0.f,2.f};
        effect2->offset = {sprite->getSize().x/2,sprite->getSize().y};
        effect->offset = {sprite->getSize().x/2,sprite->getSize().y};

        hitbox = AddComponent<Hitbox>();
        hitbox->start(sprite->getSize());
    };
    std::shared_ptr<SimpleSprite> sprite;
    std::shared_ptr<RandomMover> mover;
    std::shared_ptr<KeyboardMover> key;
    std::shared_ptr<ParticleEffect> effect;
    std::shared_ptr<ParticleEffect> effect2;
    std::shared_ptr<Hitbox> hitbox;
};



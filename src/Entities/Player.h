#pragma once
#include "Entity.h"
#include "SimpleSprite.h"
#include "RandomMover.h"
#include "KeyboardMover.h"
#include "ParticleEffect.h"
#include "Hitbox.h"
#include "Health.h"
#include "Healthbar.h"
#include "Aura.h"
#include "InvisibiltyMode.h"

class Player : public Entity{
public:
    Player(){
        sprite = AddComponent<SimpleSprite>();
        sprite->setSize({100,100});
        sprite->load("data/rocket.png");
        key = AddComponent<KeyboardMover>();
        effect = AddComponent<ParticleEffect>();
        health = AddComponent<Health>();
        health->start(1000);
        effect->start(1000,{250, 130, 0},{250, 25, 0},3.f,2.f);
        effect->gravity_direction = {0.f,5.f};
        effect2 = AddComponent<ParticleEffect>();
        effect2->start(100,{196, 196, 196},{196, 196, 196},3.f,2.f);
        effect2->gravity_direction = {0.f,6.f};
        effect2->offset = {sprite->getSize().x/2,sprite->getSize().y};
        effect->offset = {sprite->getSize().x/2,sprite->getSize().y};
        healthbar = AddComponent<Healthbar>();
        healthbar->start();
        afterburner = AddComponent<ParticleEffect>();
        afterburner->start(50,{231, 250, 0},{250, 209, 0},1.f,0.5f);
        afterburner->offset = {sprite->getSize().x/2,sprite->getSize().y};
        afterburner->gravity_direction={0.f,5.f};
        afterburner->gravity = 2000.f;
        afterburner->active = false;
        hitbox = AddComponent<Hitbox>();
        hitbox->start(sprite->getSize());
        aura = AddComponent<Aura>();
        aura->start();
        invmode = AddComponent<InvisibiltyMode>();
        invmode->start(5.f);
        invmode->trigger();
    };

    std::shared_ptr<SimpleSprite> sprite;
    std::shared_ptr<KeyboardMover> key;
    std::shared_ptr<ParticleEffect> effect;
    std::shared_ptr<ParticleEffect> effect2;
    std::shared_ptr<ParticleEffect> afterburner;
    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<Health> health;
    std::shared_ptr<Healthbar> healthbar;
    std::shared_ptr<Aura> aura;
    std::shared_ptr<InvisibiltyMode> invmode;
};



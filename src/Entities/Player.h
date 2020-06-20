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
#include "EnergyCore.h"

class Player : public Entity{
public:
    Player(){
        healthbar = AddComponent<Healthbar>();
        aura = AddComponent<Aura>();
        effect2 = AddComponent<ParticleEffect>();
        afterburner = AddComponent<ParticleEffect>();
        sprite = AddComponent<SimpleSprite>();
        energycore = AddComponent<EnergyCore>();
        hitbox = AddComponent<Hitbox>();
        sprite->setSize({100,100});
        sprite->load("data/rocket.png");
        key = AddComponent<KeyboardMover>();
        effect = AddComponent<ParticleEffect>();
        health = AddComponent<Health>();
        aura = AddComponent<Aura>();
        invmode = AddComponent<InvisibiltyMode>();
        health->start(1000);
        effect->start(1000,{250, 130, 0},{250, 25, 0},3.f,2.f);
        effect->gravity_direction = {0.f,5.f};
        effect2->start(100,{196, 196, 196},{196, 196, 196},3.f,2.f);
        effect2->gravity_direction = {0.f,6.f};
        effect2->offset = {sprite->getSize().x/2,sprite->getSize().y};
        effect->offset = {sprite->getSize().x/2,sprite->getSize().y};
        healthbar->start();
        energycore->start();
        afterburner->start(50,{194, 244, 255},{36, 217, 255},0.06f,0.05f);
        afterburner->offset = {sprite->getSize().x/2,sprite->getSize().y/2.f};
        afterburner->gravity_direction={0.f,0.f};
        afterburner->gravity = 2000.f;
        afterburner->active = false;
        hitbox->start(sprite->getSize());
        aura->start();
        invmode->start(1.f);
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
    std::shared_ptr<EnergyCore> energycore;
    std::shared_ptr<Aura> aura;
    std::shared_ptr<InvisibiltyMode> invmode;
};



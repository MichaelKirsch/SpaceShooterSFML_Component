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
#include "Gun.h"
#include "Animation.h"
#include "Text.h"
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
        key = AddComponent<KeyboardMover>();
        effect = AddComponent<ParticleEffect>();
        health = AddComponent<Health>();
        invmode = AddComponent<InvisibiltyMode>();
        gun = AddComponent<Gun>();
        smoke = AddComponent<SimpleSprite>();
        smoke_animation = AddComponent<Animation>();
        health_text =AddComponent<Text>();
    };

    void start(sf::RenderWindow& window, std::string ship, std::string gun,std::string particle1, std::string particle2);


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
    std::shared_ptr<Gun> gun;
    std::shared_ptr<SimpleSprite> smoke;
    std::shared_ptr<Animation> smoke_animation;
    std::shared_ptr<Text> health_text;
    int cash=0;
};



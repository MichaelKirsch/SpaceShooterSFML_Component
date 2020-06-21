#pragma once
#include "Entity.h"
#include "Hitbox.h"
#include "ParticleEffect.h"
#include "LinearMover.h"
#include "Health.h"
#include "Healthbar.h"
#include "Animation.h"
class Enemy : public Entity {
public:
    Enemy(){
        body = AddComponent<SimpleSprite>();
        body->setSize({100.f,100.f});
        body->load("data/a10000.png");
        mover = AddComponent<LinearMover>();
        mover->start({0.f,1.f},250.f);
        hitbox = AddComponent<Hitbox>();
        hitbox->start(body->getSize());
        particles = AddComponent<ParticleEffect>();
        particles->start(10,{255, 15, 15},{255, 36, 242},0.07f,0.03f);
        particles->gravity_direction={0.f,-1.f};
        particles->offset = body->getSize()/2.f;
        animation = AddComponent<Animation>();
        animation->start(body);
        animation->configureTextureAtlas("data/Coins/asteroid_grey_atlas.png",{3,5},0.1f,0);
        health = AddComponent<Health>();
        health->start(150);
        bar = AddComponent<Healthbar>();
        bar->start();
    };
    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<ParticleEffect> particles;
    std::shared_ptr<SimpleSprite> body;
    std::shared_ptr<LinearMover> mover;
    std::shared_ptr<Animation> animation;
    std::shared_ptr<Health> health;
    std::shared_ptr<Healthbar> bar;
private:
};



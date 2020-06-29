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
        mover = AddComponent<LinearMover>();
        hitbox = AddComponent<Hitbox>();
        particles = AddComponent<ParticleEffect>();
        animation = AddComponent<Animation>();
        health = AddComponent<Health>();
    };

    void start(sf::RenderWindow& window){
        body->setSize({window.getSize().x*0.1f,window.getSize().y*0.1f});
        body->load("data/a10000.png");
        mover->start({0.f,1.f},250.f);
        hitbox->start(body->getSize());
        particles->start(10,sf::Color::White,sf::Color::White,0.07f,0.03f);
        particles->gravity_direction={0.f,-1.f};
        particles->offset = body->getSize()/2.f;
        particles->setParticleTexture("data/invisible_icon.png");
        animation->start(body);
        animation->configureTextureAtlas("data/Coins/asteroid_grey_atlas.png",{3,5},0.1f,0);
        health->start(150);
    }


    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<ParticleEffect> particles;
    std::shared_ptr<SimpleSprite> body;
    std::shared_ptr<LinearMover> mover;
    std::shared_ptr<Animation> animation;
    std::shared_ptr<Health> health;
private:
};



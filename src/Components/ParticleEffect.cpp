//
// Created by micha on 14.06.2020.
//

#include "ParticleEffect.h"

ParticleEffect::ParticleEffect(Entity *owner) : Component(owner) {

}

void ParticleEffect::update(float deltaTime) {
    for(auto& p:m_particles)
    {
        p.update_lifetime(deltaTime);
        if(!p.alife)
            respawm(p);
    }
}

void ParticleEffect::draw(sf::RenderWindow &window) {
    for(auto& p: m_particles)
        window.draw(p.body);
}

void ParticleEffect::start(int number, sf::Color beg, sf::Color end, float life_max, float life_min) {
    m_particles.reserve(number);
    m_particles.resize(number);
    begin_color = beg;
    end_color = end;
    lifetime_min = life_min;
    lifetime_max = life_max;

    gravity_direction = {0.f,-2.f};

    for(auto& p:m_particles)
    {
        respawm(p);
    }
}

void ParticleEffect::respawm(Particle &p) {

    sf::Color difference_color = end_color-begin_color;
    difference_color.r *=(rand()%100)*0.01f;
    difference_color.g *=(rand()%100)*0.01f;
    difference_color.b *=(rand()%100)*0.01f;
    p.body.setFillColor(begin_color+difference_color);
    p.body.setSize({10.f,10.f});
    p.body.setPosition(owner->transform->getPosition()+offset);
    p.position = owner->transform->getPosition()+offset;
    p.gravity = gravity_direction;
    float rand_x = (100-rand()%200)*0.01f;
    float rand_y = (100-rand()%200)*0.01f;
    p.direction.x = rand_x;
    p.direction.y = rand_y;
    p.lifetime = lifetime_min +((rand()%100)*0.01f)*(lifetime_min +lifetime_max);
    p.alife = true;
    p.time_alife = 0.f;
}

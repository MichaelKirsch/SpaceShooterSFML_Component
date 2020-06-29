#pragma once
#include "Component.h"
#include "Entity.h"

struct Particle
{
    sf::RectangleShape body;
    sf::Vector2f direction;
    sf::Vector2f position;
    float time_alife;
    float lifetime;
    bool alife=true;
    sf::Vector2f gravity;

    void update_lifetime(float elapsed)
    {
        time_alife+=elapsed;
        if(lifetime<time_alife)
            alife = false;
        position+=(direction+gravity)*elapsed*250.f;
        body.setPosition(position);
    }
};


class ParticleEffect : public Component{
public:
    ParticleEffect(Entity* owner);

    void start(int number, sf::Color beg, sf::Color end, float life_max, float life_min,sf::Vector2f size={10.f,10.f});
    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    float smallest=0.f;
    float biggest=10.f;
    sf::Color begin_color;
    sf::Color end_color;
    float lifetime_min;
    float lifetime_max;
    int num_particles;
    float gravity;
    sf::Vector2f gravity_direction;
    sf::Vector2f offset;
    void setParticleSize(sf::Vector2f size);

private:
    sf::Vector2f partice_size;
    void respawm(Particle& p);

    std::vector<Particle> m_particles;

};



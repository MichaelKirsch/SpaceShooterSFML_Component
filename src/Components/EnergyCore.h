#pragma once
#include "Component.h"
#include "Entity.h"
#include "SimpleSprite.h"
#include "Health.h"
#include "ParticleEffect.h"

class EnergyCore : public Component{
public:
    EnergyCore(Entity* owner);
    void setColorForeground(sf::Color color);

    void start() override;

    void update(float deltaTime) override;
    void lateUpdate(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    sf::Vector2f offset={0.f,0.f};

private:

    sf::RectangleShape m_core;
    sf::Texture m_texture;
    std::shared_ptr<Health> ownerHealth;
    std::shared_ptr<ParticleEffect> particles;

    sf::Color m_colorForeground;
    sf::CircleShape foreground;

    int actualHealthPercent;
    sf::Vector2f sizeOfOwner;
    float actualHealthRaw;
};





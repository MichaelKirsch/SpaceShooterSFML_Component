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


private:
    std::shared_ptr<SimpleSprite> m_core;

    std::shared_ptr<Health> ownerHealth;
    std::shared_ptr<ParticleEffect> particles;

    sf::Color m_colorForeground;
    sf::CircleShape foreground;

    int actualHealthPercent;
    sf::Vector2f sizeOfOwner;
    float actualHealthRaw;
};





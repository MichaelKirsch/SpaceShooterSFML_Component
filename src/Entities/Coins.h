#pragma once
#include "Entity.h"
#include "LinearMover.h"
#include "SimpleSprite.h"
#include "Animation.h"
#include "Hitbox.h"
#include "ParticleEffect.h"

class Coins : public Entity {
public:
    enum class CoinType
    {
        GOLD,BRONZE,SILVER
    };

    Coins(){
        mover = AddComponent<LinearMover>();
        sprite = AddComponent<SimpleSprite>();
        animation = AddComponent<Animation>();
        hitbox = AddComponent<Hitbox>();
        effect = AddComponent<ParticleEffect>();
    };

    const CoinType& getCoinType()
    {
        return m_type;
    }

    int getValue();
    void start(CoinType i_type,sf::RenderWindow& window);

    std::shared_ptr<LinearMover> mover;
    std::shared_ptr<SimpleSprite>sprite;
    std::shared_ptr<Animation> animation;
    std::shared_ptr<Hitbox> hitbox;
    std::shared_ptr<ParticleEffect> effect;
private:
    CoinType m_type;
};



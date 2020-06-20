#pragma once
#include "Entity.h"
#include "LinearMover.h"
#include "SimpleSprite.h"
#include "Animation.h"
#include "Hitbox.h"

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
private:
    CoinType m_type;
};



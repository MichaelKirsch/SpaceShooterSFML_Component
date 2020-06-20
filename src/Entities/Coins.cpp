//
// Created by micha on 18.06.2020.
//

#include "Coins.h"

void Coins::start(Coins::CoinType i_type, sf::RenderWindow &window) {
    sprite->start();
    sprite->load("data/Coins/Coins-PNG.png");
    sprite->setSize({window.getSize().x*0.05f,window.getSize().y*0.05f});
    animation->start(sprite);
    mover->start({0.f,1.f},100.f);
    switch (i_type) {
        case CoinType::SILVER:
            animation->configureTextureAtlas("data/Coins/coins_silver_atlas.png",{3,3},0.05f,1);
            mover->speed=300.f;
            break;
        case CoinType::GOLD:
            animation->configureTextureAtlas("data/Coins/coins_gold_atlas.png",{3,3},0.05f,1);
            mover->speed=400.f;
            break;
        case CoinType::BRONZE:
            animation->configureTextureAtlas("data/Coins/coins_bronze_atlas.png",{3,3},0.05f,1);
            mover->speed=200.f;
            break;
    }
    hitbox->start(sprite->getSize());
    m_type = i_type;
}

int Coins::getValue() {
    switch (m_type) {
        case CoinType::SILVER:
            return 100;
        case CoinType::GOLD:
            return 200;
        case CoinType::BRONZE:
            return 50;
    }
}

//
// Created by Dennis on 19/06/2020.
//

#pragma once

#include "SimpleSprite.h"
#include "Entity.h"

class SpaceBackground: public Entity {
public:
    SpaceBackground(){
        sprite = AddComponent<SimpleSprite>();
    }
    ~SpaceBackground() = default;

    void start(sf::RenderWindow& window, std::string filename);

    void draw(sf::RenderWindow &window) override;

    std::shared_ptr<SimpleSprite> sprite;


};





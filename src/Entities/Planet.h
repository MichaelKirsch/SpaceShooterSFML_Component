//
// Created by Dennis on 20/06/2020.
//

#pragma once
#include "Entity.h"
#include "LinearMover.h"
#include "CircleShape.h"
#include "MouseOver.h"

class Planet: public Entity{
public:
    Planet();
    ~Planet() = default;

    void start(sf::RenderWindow &window);


private:
    std::shared_ptr<CircleShape> m_planet;
    std::shared_ptr<LinearMover> m_linearmover;
};





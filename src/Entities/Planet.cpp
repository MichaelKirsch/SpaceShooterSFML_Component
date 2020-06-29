//
// Created by Dennis on 20/06/2020.
//

#include "Planet.h"

void Planet::start(sf::RenderWindow &window) {
    m_planet->setSize(float(window.getSize().x * 0.1f));
    m_planet->load("data/a10000.png");
    m_linearmover->start({0.f, 1.f}, 100.f);
}


Planet::Planet() {
    m_planet = AddComponent<CircleShape>();
    m_linearmover = AddComponent<LinearMover>();
}


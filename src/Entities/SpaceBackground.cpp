//
// Created by Dennis on 19/06/2020.
//

#include "SpaceBackground.h"

void SpaceBackground::start(sf::RenderWindow &window) {
    sprite->setSize({float(window.getSize().x), float(window.getSize().y)});
    sprite->load("data/spacebackground.jpg");

}

void SpaceBackground::draw(sf::RenderWindow &window) {
    sprite->draw(window);
}

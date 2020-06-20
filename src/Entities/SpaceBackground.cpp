//
// Created by Dennis on 19/06/2020.
//

#include "SpaceBackground.h"

void SpaceBackground::start(sf::RenderWindow &window, std::string filename) {
    sprite->setSize({float(window.getSize().x), float(window.getSize().y)});
    sprite->load(filename);

}

void SpaceBackground::draw(sf::RenderWindow &window) {
    sprite->draw(window);
}

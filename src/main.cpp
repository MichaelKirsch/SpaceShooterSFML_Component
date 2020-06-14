
#include <iostream>
#include "Entity.h"
#include "SimpleSprite.h"
#include "Player.h"



int main() {
    sf::RenderWindow window(sf::VideoMode(1000,1000),"Hello");
    Player player;
    sf::Clock vl;
    float elapsed = vl.restart().asSeconds();

    window.setFramerateLimit(30);
    player.mover->active = false;
    player.effect->gravity_direction={0.f,5.f};

    while(window.isOpen())
    {
        elapsed = vl.restart().asSeconds();

        window.clear();
        player.transform->setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
        player.draw(window);
        player.update(elapsed);
        player.lateUpdate(elapsed);
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
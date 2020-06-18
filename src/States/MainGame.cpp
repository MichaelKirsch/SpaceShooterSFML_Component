//
// Created by micha on 18.06.2020.
//

#include "MainGame.h"

void MainGame::update(float deltaTime) {
    player->update(deltaTime);
    player->lateUpdate(deltaTime);
    for(auto& e:allEnemies)
    {
        e.update(deltaTime);
        if(e.hitbox->AABBCollisionTest(player->hitbox))
            e.transform->setPosition(rand()%m_window->getSize().x,0.f);
        if(e.transform->getY()>m_window->getSize().y)
        {
            e.transform->setPosition(rand()%m_window->getSize().x,0.f);
            e.mover->speed+=50.f+rand()%6;
        }

    }
}

void MainGame::draw(sf::RenderWindow &window) {
    window.clear();
    for(auto& e:allEntities)
        e->draw(window);

    for(auto& e:allEnemies)
    {
        e.draw(window);
    }

    window.display();
}

void MainGame::inputs() {
    player->transform->setX(sf::Mouse::getPosition(*m_window).x);
    player->transform->setY(sf::Mouse::getPosition(*m_window).y);
}

MainGame::MainGame(sf::RenderWindow &window) {
    window.setMouseCursorVisible(false);
    m_window = &window;
    player = std::make_shared<Player>();
    player->start();
    player->effect->active = true;
    player->effect2->active = true;
    allEntities.push_back(player);

    for(auto& e:allEnemies)
    {
        e.start();
        e.transform->setX(rand()%window.getSize().x);
    }
}



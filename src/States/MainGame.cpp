#include "MainGame.h"

void MainGame::update(float deltaTime) {
    player->update(deltaTime);
    player->lateUpdate(deltaTime);
    for(auto& e:allEnemies)
    {
        e.update(deltaTime);
        if(e.hitbox->AABBCollisionTest(player->hitbox))
        {
            e.transform->setPosition(rand()%m_window->getSize().x,0.f);
            player->health->inflictDamagePercent(10);
        }
        if(e.transform->getY()>m_window->getSize().y)
        {
            e.transform->setPosition(rand()%m_window->getSize().x,0.f);
            e.mover->speed+=50.f+rand()%6;
            score++;
        }
    }
    for(auto& f:powerups)
    {
        f.update(deltaTime);
        if(f.hitbox->AABBCollisionTest(player->hitbox))
        {
            player->health->rechargePercent(10);
            f.transform->setPosition(rand()%m_window->getSize().x,0.f);
        }

        if(f.transform->getY()>m_window->getSize().y*3) //gets reset very late
        {
            f.transform->setPosition(rand()%m_window->getSize().x,0.f);
        }
    }

    scoreText.setString("Score:"+std::to_string(score));
    trailtext.setString("Health: "+ std::to_string(player->health->getHealthPercent())+ "%");
    if(!player->health->isAlife())
    {
        stm->setNextState(std::make_shared<TestState>(stm,*m_window));
        //switch to new state somehow
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

    for(auto& f:powerups)
    {
        f.draw(window);
    }

    window.draw(scoreText);
    window.draw(trailtext);


    window.display();
}

void MainGame::inputs() {
    player->transform->setX(sf::Mouse::getPosition(*m_window).x);
    player->transform->setY(sf::Mouse::getPosition(*m_window).y);
}

MainGame::MainGame(Statemachine* st,sf::RenderWindow &window) : State(st) {
    font.loadFromFile("data/Fonts/JetBrainsMono-Bold.ttf");
    scoreText.setFont(font);
    trailtext.setFont(font);
    scoreText.setCharacterSize(window.getSize().x*0.07f);
    trailtext.setCharacterSize(window.getSize().x*0.05f);
    trailtext.setPosition(0.f,window.getSize().x*0.08f);
    scoreText.setFillColor(sf::Color::Yellow);
    trailtext.setFillColor(sf::Color::Magenta);
    window.setMouseCursorVisible(false);
    m_window = &window;
    player = std::make_shared<Player>();
    player->start();
    allEntities.push_back(player);

    for(auto& e:allEnemies)
    {
        e.start();
        e.transform->setX(rand()%window.getSize().x);
    }
    for(auto& f:powerups)
    {
        f.transform->setX(rand()%window.getSize().x);
        f.mover->speed =200.f;
    }


}

MainGame::~MainGame() {
    std::cout << "Main Game goes out of scope" << std::endl;
}



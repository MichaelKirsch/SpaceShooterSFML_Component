#include "MainGame.h"

MainGame::MainGame(Statemachine* st,sf::RenderWindow &window) : State(st) {
    newBackground.start(window,"data/space-1.png");
    newPlanet.start(window);
    font.loadFromFile("data/Fonts/JetBrainsMono-Bold.ttf");
    scoreText.setFont(font);
    trailtext.setFont(font);
    scoreText.setCharacterSize(window.getSize().x*0.04f);
    trailtext.setCharacterSize(window.getSize().x*0.04f);
    trailtext.setPosition(0.f,window.getSize().x*0.06f);
    scoreText.setFillColor(sf::Color::Yellow);
    trailtext.setFillColor(sf::Color::Magenta);
    window.setMouseCursorVisible(false);
    m_window = &window;
    player.start(window);
    coin.start(Coins::CoinType::BRONZE,window);
    coin2.start(Coins::CoinType::SILVER,window);
    coin3.start(Coins::CoinType::GOLD,window);
    invis.transform->setX(rand()%window.getSize().x);
    invis.transform->setY(0.f);
    for(auto& e:allEnemies)
    {
        e.start();
        e.transform->setX(rand()%window.getSize().x);
    }
    for(auto& f:powerups)
    {
        f.transform->setX(rand()%window.getSize().x);
        f.mover->speed = 200.f;
    }

}

MainGame::~MainGame() {
    std::cout << "Main Game goes out of scope" << std::endl;
}


void MainGame::update(float deltaTime) {
    newPlanet.update(deltaTime);
    player.update(deltaTime);
    player.lateUpdate(deltaTime);
    coin.update(deltaTime);
    coin2.update(deltaTime);
    coin3.update(deltaTime);

    if(coin.transform->getY()>m_window->getSize().y)
        coin.transform->setPosition(rand()%m_window->getSize().x,0.f);

    if(coin2.transform->getY()>m_window->getSize().y)
        coin2.transform->setPosition(rand()%m_window->getSize().x,0.f);
    if(coin3.transform->getY()>m_window->getSize().y)
        coin3.transform->setPosition(rand()%m_window->getSize().x,0.f);

    if(coin.hitbox->AABBCollisionTest(player.hitbox))
    {
        coin.transform->setPosition(rand()%m_window->getSize().x,0.f);
        player.cash+=coin.getValue();
    }
    if(player.transform->getY()<0.f || player.transform->getY()>m_window->getSize().y ||
    player.transform->getX()<0.f ||player.transform->getX()>m_window->getSize().x)
        player.health->inflictDamagePercent(1.f);

    for(auto& e:allEnemies)
    {
        e.update(deltaTime);
        if(!player.invmode->isInvisible())
            if(e.hitbox->AABBCollisionTest(player.hitbox))
            {
                e.transform->setPosition(rand()%m_window->getSize().x,0.f);
                player.health->inflictDamagePercent(25);
            }
        if(e.transform->getY()>m_window->getSize().y)
        {
            e.transform->setPosition(rand()%m_window->getSize().x,0.f);
            e.mover->speed=getAddSpeed(score,max_speed_var,startSpeed);
            score++;
        }
    }
    for(auto& f:powerups)
    {
        f.update(deltaTime);
        if(f.hitbox->AABBCollisionTest(player.hitbox))
        {
            player.health->rechargePercent(10);
            f.transform->setPosition(rand()%m_window->getSize().x,0.f);
        }

        if(f.transform->getY()>m_window->getSize().y*3) //gets reset very late
        {
            f.transform->setPosition(rand()%m_window->getSize().x,-rand()%500);
        }
    }

    invis.update(deltaTime);
    if(invis.transform->getY()>m_window->getSize().y)
        invis.transform->setPosition(rand()%m_window->getSize().x,-rand()%1000);
    if(invis.hitbox->AABBCollisionTest(player.hitbox))
    {
        player.invmode->trigger();
        invis.transform->setPosition(rand()%m_window->getSize().x,-rand()%1000);
    }
    player.aura->active = player.invmode->isInvisible();
    player.afterburner->active =  player.invmode->isInvisible();
    player.smoke->active = player.health->getHealthPercent()<10.f;

    scoreText.setString("Score:"+std::to_string(score)+ " Cash:"+std::to_string(player.cash));
    //player.health_text->setText("Health: "+ std::to_string(player.health->getHealthPercent())+ "%");
    player.health_text->setText("AMMO: "+ std::to_string(player.gun->getAmmo()));
    if(!player.health->isAlife())
    {
        auto s = std::make_shared<TestState>(stm,*m_window);
        s->score = score;
        stm->setNextState(s);
    }

}

void MainGame::draw(sf::RenderWindow &window) {
    window.clear();

    newBackground.draw(window);
    newPlanet.draw(window);
    player.draw(window);

    for(auto& e:allEnemies)
    {
        e.draw(window);
    }

    for(auto& f:powerups)
    {
        f.draw(window);
    }
    invis.draw(window);
    coin.draw(window);
    coin2.draw(window);
    coin3.draw(window);
    window.draw(scoreText);
    window.draw(trailtext);
    window.display();
}

void MainGame::inputs() {
    player.transform->setX(sf::Mouse::getPosition(*m_window).x);
    player.transform->setY(sf::Mouse::getPosition(*m_window).y);
}



float MainGame::getAddSpeed(int stage, float max_speed_control, float offset) {
    return offset+log10(stage)*max_speed_control;
}





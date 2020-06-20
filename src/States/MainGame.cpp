#include "MainGame.h"

MainGame::MainGame(Statemachine* st,sf::RenderWindow &window) : State(st) {
    newBackground.start(window);
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
    player.update(deltaTime);
    player.lateUpdate(deltaTime);
    coin.update(deltaTime);

    if(coin.transform->getY()>m_window->getSize().y)
        coin.transform->setPosition(rand()%m_window->getSize().x,0.f);
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


    scoreText.setString("Score:"+std::to_string(score)+ " Cash:"+std::to_string(player.cash));
    trailtext.setString("Health: "+ std::to_string(player.health->getHealthPercent())+ "%");

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





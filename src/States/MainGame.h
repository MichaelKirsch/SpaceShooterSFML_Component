#pragma once
#include "StateMachine/State.h"
#include "Entity.h"
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include "Entities/HealthPowerUp.h"
#include "TestState.h"
#include "StateMachine/Statemachine.h"

class MainGame : public State {
public:
    MainGame(Statemachine* st,sf::RenderWindow& window);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    void inputs() override;

    ~MainGame();
private:
    sf::Font font;
    sf::Text scoreText, trailtext;
    sf::RenderWindow* m_window;
    std::shared_ptr<Player> player;
    std::array<Enemy,5> allEnemies;
    std::vector<std::shared_ptr<Entity>> allEntities;
    std::array<HealthPowerUp,1> powerups;
    int score=0;

};



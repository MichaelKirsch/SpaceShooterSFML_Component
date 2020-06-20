#pragma once
#include "StateMachine/State.h"
#include "Entity.h"
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include "Entities/HealthPowerUp.h"
#include "TestState.h"
#include "StateMachine/Statemachine.h"
#include <cmath>
#include "Entities/InvisibleToken.h"
#include "Entities/SpaceBackground.h"
#include "Entities/Coins.h"


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
    Player player;
    std::array<Enemy,6> allEnemies;
    std::vector<std::shared_ptr<Entity>> allEntities;
    std::array<HealthPowerUp,1> powerups;
    Coins coin,coin2,coin3;
    SpaceBackground newBackground;
    InvisibleToken invis;
    int score=0;
    const float max_speed_var = 400.f;
    const float startSpeed = 200.f;
    float getAddSpeed(int stage,float max_speed_control, float offset);
};



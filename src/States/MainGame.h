#pragma once
#include "StateMachine/State.h"
#include "Entity.h"
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include "Entities/PowerUp.h"
#include "TestState.h"
#include "StateMachine/Statemachine.h"
#include <cmath>
#include "Entities/SpaceBackground.h"
#include "Entities/Coins.h"
#include "Entities/Planet.h"
#include "Entities/Button.h"
#include "StartupScreen.h"

//
class MainGame : public State {
public:
    MainGame(Statemachine* st,sf::RenderWindow& window);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    void inputs() override;

    ~MainGame();

    int difficulty=0;

    std::string name ="";

private:

    sf::Font font;
    sf::Text scoreText, trailtext;
    sf::RenderWindow* m_window;
    Player player;
    std::array<Enemy,6> allEnemies;
    std::vector<std::shared_ptr<Entity>> allEntities;
    PowerUp health,shield;
    Coins coin;
    SpaceBackground newBackground;
    Planet newPlanet;

    int score=0;
    float max_speed_var = 300.f;
    const float startSpeed = 200.f;
    float getAddSpeed(int stage,float max_speed_control, float offset);
};



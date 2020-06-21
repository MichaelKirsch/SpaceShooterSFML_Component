#pragma once
#include "StateMachine/State.h"
#include "MainGame.h"
class StartupScreen : public State {
public:
    StartupScreen(Statemachine* st, sf::RenderWindow& win);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    void inputs() override;

private:
    sf::RenderWindow* m_window;
    sf::Font font;
    sf::Text text,nametext;
    std::string name="";
};



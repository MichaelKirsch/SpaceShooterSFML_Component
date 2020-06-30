#pragma once
#include "Engine/StateMachine/State.h"
#include "StateMachine/Statemachine.h"
#include "MainGame.h"
#include "SimpleText.h"
#include "Button.h"

class
TestState : public State {
public:
    TestState(Statemachine* st,sf::RenderWindow& window);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;
    int score=0;
    int dif=0;
    std::string name="";
    void inputs() override;
    ~TestState();
private:
    Button restart;
    SimpleText text;
    sf::RenderWindow* m_window;
};



#pragma once
#include "State.h"
#include <memory>
#include "SFML/Graphics.hpp"



class Statemachine {
public:
    Statemachine();
    void run();
    void setNextState(std::shared_ptr<State> newState)
    {
        nextState = newState;
        oldstate = playedState;
    };
    std::shared_ptr<State> oldstate;
private:
    int framerate = 60;
    int tickrate = 60;

    std::shared_ptr<State> playedState;
    std::shared_ptr<State> nextState;
    sf::RenderWindow window;
    sf::Clock timer;
    float frametimer,ticktimer;
    float elapsed;
};



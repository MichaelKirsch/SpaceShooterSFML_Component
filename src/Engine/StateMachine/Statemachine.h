#pragma once
#include "State.h"
#include <memory>
#include "SFML/Graphics.hpp"



class Statemachine {
public:
    Statemachine();
    void run();
    std::shared_ptr<State> setNextState(std::shared_ptr<State> newState)
    {
        nextState = newState;
        return playedState; //return played state to maybe get back to it
    };

private:
    int framerate = 60;
    int tickrate = 30;
    std::shared_ptr<State> playedState;
    std::shared_ptr<State> nextState;
    sf::RenderWindow window;
    sf::Clock timer;
    float frametimer,ticktimer;
    float elapsed;
};



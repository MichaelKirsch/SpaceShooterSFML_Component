#pragma once
#include "State.h"
#include <memory>
#include "SFML/Graphics.hpp"



class Statemachine {
public:
    Statemachine();
    void run();
    void switch_state(){};

private:
    int framerate = 60;
    int tickrate = 30;
    std::unique_ptr<State> playedState;
    sf::RenderWindow window;
    sf::Clock timer;
    float frametimer,ticktimer;
    float elapsed;
};



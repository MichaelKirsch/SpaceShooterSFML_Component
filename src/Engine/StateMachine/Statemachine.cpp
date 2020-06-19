//
// Created by micha on 18.06.2020.
//

#include "Statemachine.h"
#include "States/MainGame.h"

void Statemachine::run() {
    elapsed = 0.f;
    frametimer = 0.f;
    ticktimer = 0.f;
    nextState = playedState;

    while (window.isOpen())
    {
        elapsed = timer.restart().asSeconds();
        frametimer += elapsed;
        ticktimer +=elapsed;
        if (ticktimer>1.f/tickrate)
        {

            playedState->update(ticktimer);
            playedState->inputs();
            ticktimer = 0.f;
        }
        if(frametimer>1.f/framerate)
        {
            playedState->draw(window);
            frametimer =0.f;
        }

        sf::Event e;
        while (window.pollEvent(e))
            if(e.type == sf::Event::Closed)
                window.close();
        if(nextState !=playedState)
            playedState = nextState;
    }
}

Statemachine::Statemachine() {
    window.create(sf::VideoMode(1000,1000),"SpaceShooter");
    playedState = std::make_shared<MainGame>(this,window);
}

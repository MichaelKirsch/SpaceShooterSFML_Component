//
// Created by micha on 18.06.2020.
//

#include "Statemachine.h"
#include "States/MainGame.h"
#include "States/StartupScreen.h"
#include <thread>

Statemachine::Statemachine() {
    window.create(sf::VideoMode(1000,1000),"SpaceShooter");
    playedState = std::make_shared<StartupScreen>(this,window);
}

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
        if(frametimer>=1.f/framerate)
        {
            playedState->draw(window);
            frametimer =0.f;
        }
        if (ticktimer>=1.f/tickrate)
        {

            playedState->update(ticktimer);
            playedState->inputs();
            ticktimer = 0.f;
        }
        if(nextState !=playedState)
            playedState = nextState;

        float neededTime_frame = (1.f/framerate)-frametimer;
        float neededTime_tick = (1.f/tickrate)-ticktimer;
        std::this_thread::sleep_for(std::chrono::milliseconds(int(((neededTime_frame<neededTime_tick)?neededTime_frame:neededTime_tick)*990)));
    }
}



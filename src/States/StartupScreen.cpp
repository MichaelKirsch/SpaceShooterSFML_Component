//
// Created by micha on 19.06.2020.
//

#include "StartupScreen.h"

StartupScreen::StartupScreen(Statemachine *st, sf::RenderWindow &sf) : State(st){
    m_window = &sf;
    font.loadFromFile("data/Fonts/JetBrainsMono-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(sf.getSize().y*0.05f);
    text.setFillColor(sf::Color::Red);
    text.setString("Welcome to SpaceRace\nPress Left Mouse to start");
}

void StartupScreen::update(float deltaTime) {

}

void StartupScreen::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(text);
    window.display();
}

void StartupScreen::inputs() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        stm->setNextState(std::make_shared<MainGame>(stm,*m_window));
    }
}



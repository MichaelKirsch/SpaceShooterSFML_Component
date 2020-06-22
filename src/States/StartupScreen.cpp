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
    text.setString("Welcome to SpaceRace\nPlease Enter your Name\nand then press Left Mouse:\n");
    nametext.setFont(font);
    nametext.setCharacterSize(sf.getSize().y*0.05f);
    nametext.setFillColor(sf::Color::Yellow);
    nametext.setPosition(0.f,m_window->getSize().y/2.f);
    //m_window->create(sf::VideoMode::getDesktopMode(),"sda0");
}

void StartupScreen::update(float deltaTime) {
    nametext.setString(name);
}

void StartupScreen::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(text);
    window.draw(nametext);
    window.display();
    sf::Event e;
    while (window.pollEvent(e))
        if(e.type == sf::Event::Closed)
            window.close();
        if(e.type==sf::Event::TextEntered)
        {
            name+=static_cast<char>(e.text.unicode);
        }

}

void StartupScreen::inputs() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&name!="")
    {
        auto z = std::make_shared<MainGame>(stm,*m_window);
        z->name = name;
        stm->setNextState(z);
    }
}



//
// Created by micha on 19.06.2020.
//

#include "StartupScreen.h"

StartupScreen::StartupScreen(Statemachine *st, sf::RenderWindow &sf_window) : State(st){
    m_window = &sf_window;
    //m_window->create(sf::VideoMode::getDesktopMode(),"sda0");
    welcomwtext.text->start(float(m_window->getSize().y*0.04),"Welcome to SpaceRace","data/Fonts/Kenney Rocket.ttf",sf::Color::Green);
    welcomwtext.transform->setPosition(float(m_window->getSize().x*0.15),0.f);
    buttontest.start(*m_window,{float(m_window->getSize().x*0.5),float(m_window->getSize().y*0.2)},{m_window->getSize().x*0.2f,m_window->getSize().x*0.1f},"data/Fonts/Kenney Rocket.ttf","data/UI/buttonLong_blue.png","Start");
    namefield.start(*m_window,{float(m_window->getSize().x*0.3),float(m_window->getSize().y*0.2)},{m_window->getSize().x*0.2f,m_window->getSize().x*0.1f},"data/Fonts/Kenney Rocket.ttf","data/UI/buttonLong_blue.png","Start");

    background.start(sf_window,"data/Background/space-1.png");
    namefield.setTextColor(sf::Color::Blue);
    sprite.body->load("data/Background/space-1.png");
    sprite.body->setSize({float(m_window->getSize().x*0.3),float(m_window->getSize().y*0.3)});
    sprite.transform->setPosition({float(m_window->getSize().x*0.35),float(m_window->getSize().y*0.35)});
    sprite.animation->start(sprite.body);
    sprite.animation->configureTextureAtlas("data/AnimationAtlas/asteroid_grey_atlas.png",{3,5},0.1f);
    list.start(sf_window,{m_window->getSize().x/2.f-m_window->getSize().x*0.13f,m_window->getSize().y*0.7f},{m_window->getSize().x*0.3f,m_window->getSize().y*0.1f},"data/UI/arrowBlue_left.png","data/UI/arrowBlue_right.png","data/UI/buttonLong_blue.png","data/Fonts/Kenney Rocket.ttf");
    list.insertValue({"easy","medium","hard"});

    color_l.load("data/ColorPalettes/joy.color");

    welcomwtext.text->setColor(color_l.getColor(color_loader::good));

    }

void StartupScreen::update(float deltaTime) {
    if(name.empty())
        namefield.setText("Your Name");
    else
        namefield.setText(name);
    buttontest.update(deltaTime);
    namefield.update(deltaTime);
    sprite.update(deltaTime);
    welcomwtext.update(deltaTime);
    list.update(deltaTime);
    if(buttontest.mouse->mouseOver&&name.empty())
        buttontest.setTextColor(sf::Color::Red);
    if(buttontest.mouse->mouseOver&&!name.empty())
        buttontest.setTextColor(sf::Color::Green);
    if (!buttontest.mouse->mouseOver)
        buttontest.setTextColor(sf::Color::White);
}

void StartupScreen::draw(sf::RenderWindow &window) {
    window.clear();
    background.draw(window);
    welcomwtext.draw(window);
    buttontest.draw(window);
    namefield.draw(window);
    sprite.draw(window);
    list.draw(window);
    window.display();
    sf::Event e;
    while (window.pollEvent(e))
        if(e.type == sf::Event::Closed)
            window.close();
        if(e.type==sf::Event::TextEntered)
        {
            if(e.text.unicode==0x08&&!name.empty())
                name.pop_back();
            else
                name+=static_cast<char>(e.text.unicode);
        }

}

void StartupScreen::inputs() {
    if(buttontest.mouse->clickedLeft&&name!="")
    {
        auto z = std::make_shared<MainGame>(stm,*m_window);
        z->name = name;
        z->difficulty = list.getCurrentItemNbr();
        stm->setNextState(z);
    }
}



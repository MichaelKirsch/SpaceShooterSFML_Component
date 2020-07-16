//
// Created by micha on 19.06.2020.
//

#include "StartupScreen.h"

StartupScreen::StartupScreen(Statemachine *st, sf::RenderWindow &sf_window) : State(st){
    m_window = &sf_window;
    color_l.load("data/ColorPalettes/harmonic2.color");
    //m_window->create(sf::VideoMode::getDesktopMode(),"sda0");
    welcomwtext.text->start(float(m_window->getSize().y*0.04),"Welcome to SpaceRace","data/Fonts/Kenney Rocket.ttf",sf::Color::Green);
    welcomwtext.transform->setPosition(float(m_window->getSize().x*0.15),0.f);
    buttontest.start(*m_window,&color_l,{float(m_window->getSize().x*0.6),float(m_window->getSize().y*0.2)},{m_window->getSize().x*0.2f,m_window->getSize().x*0.1f},"data/Fonts/Kenney Rocket.ttf","data/UI/buttonLong_blue.png","Start");
    namefield.start(*m_window,&color_l,{float(m_window->getSize().x*0.2),float(m_window->getSize().y*0.2)},{m_window->getSize().x*0.3f,m_window->getSize().x*0.1f},"data/Fonts/Kenney Rocket.ttf","data/UI/buttonLong_blue.png","Start");

    background.start(sf_window,"data/Background/space-1.png");
    namefield.setTextColor(sf::Color::Blue);
    sprite.body->load("data/Background/space-1.png");
    sprite.body->setSize({float(m_window->getSize().x*0.3),float(m_window->getSize().y*0.3)});
    sprite.transform->setPosition({float(m_window->getSize().x*0.35),float(m_window->getSize().y*0.35)});
    sprite.animation->start(sprite.body);
    sprite.animation->configureTextureAtlas("data/AnimationAtlas/asteroid_grey_atlas.png",{3,5},0.05f);
    list.start(sf_window,&color_l,{m_window->getSize().x/2.f-m_window->getSize().x*0.13f,m_window->getSize().y*0.7f},{m_window->getSize().x*0.3f,m_window->getSize().y*0.1f},"data/UI/arrowBlue_left.png","data/UI/arrowBlue_right.png","data/UI/buttonLong_blue.png","data/Fonts/Kenney Rocket.ttf");
    list.insertValue({"easy","medium","hard"});
    colorschemes.start(sf_window,&color_l,{m_window->getSize().x/2.f-m_window->getSize().x*0.13f,m_window->getSize().y*0.7f+m_window->getSize().y*0.15f},{m_window->getSize().x*0.3f,m_window->getSize().y*0.1f},"data/UI/arrowBlue_left.png","data/UI/arrowBlue_right.png","data/UI/buttonLong_blue.png","data/Fonts/Kenney Rocket.ttf");
    colorschemes.insertValue({"dark_purple","joy","harmonic","harmonic2","mk1"});

    namefield.change_on_hover = false;
    welcomwtext.setColorLoader(&color_l);

    SQLite::Database db("data/database.db",SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    std::cout << "SQLite database file '" << db.getFilename().c_str() << "' opened successfully\n";

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
    colorschemes.update(deltaTime);
    if(colorschemes.has_change)
    {
        welcomwtext.highlight(true);
        color_l.load("data/ColorPalettes/"+colorschemes.getCurrentValue()+".color");
    }
}

void StartupScreen::draw(sf::RenderWindow &window) {
    window.clear();
    background.draw(window);
    welcomwtext.draw(window);
    buttontest.draw(window);
    namefield.draw(window);
    sprite.draw(window);
    list.draw(window);
    colorschemes.draw(window);
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

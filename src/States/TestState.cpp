//
// Created by micha on 19.06.2020.
//

#include "TestState.h"

void TestState::update(float deltaTime) {
    restart.update(deltaTime);
    text.update(deltaTime);
    text.text->setText(name+" Score:"+std::to_string(score));
    if(restart.hover)
        restart.setTextColor(sf::Color::Green);
    else
        restart.setTextColor(sf::Color::White);

    text.transform->setX(m_window->getSize().x/2.f-text.text->getGlobalBounds().width/2.f);
}

void TestState::draw(sf::RenderWindow &window) {
    window.clear();
    restart.draw(window);
    text.draw(window);
    window.display();
    sf::Event e;
    while (window.pollEvent(e))
        if(e.type == sf::Event::Closed)
            window.close();
}

void TestState::inputs() {
    if(restart.leftClicked_t||sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        stm->setNextState(std::make_shared<MainGame>(stm,*m_window));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_window->close();
}

TestState::TestState(Statemachine *st, sf::RenderWindow &window) : State(st){
    m_window = &window;
    text.text->start(window.getSize().y*0.06f,name+" Score:"+std::to_string(score),"data/Fonts/Kenney Space.ttf",sf::Color::Green);
    restart.start(window,{window.getSize().x*0.35f,window.getSize().y*0.35f},{window.getSize().x*0.3f,window.getSize().y*0.3f},
            "data/Fonts/Kenney Rocket.ttf","data/UI/buttonLong_blue.png","Try Again");
    m_window->setMouseCursorVisible(true);
    text.transform->setY(m_window->getSize().y*0.2f);
}

TestState::~TestState() {
    std::cout << "Test State goes out of scope" << std::endl;
}

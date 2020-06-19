//
// Created by micha on 19.06.2020.
//

#include "TestState.h"

void TestState::update(float deltaTime) {
    text.setString("This is the test State\nclick left mouse to get back\nto the normal game\nright ends game");
}

void TestState::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(rect);
    window.draw(text);
    window.display();
}

void TestState::inputs() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        m_window->close();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        stm->setNextState(std::make_shared<MainGame>(stm,*m_window));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        stm->setNextState(stm->oldstate);

}

TestState::TestState(Statemachine *st, sf::RenderWindow &window) : State(st){
    m_window = &window;
    rect.setSize({m_window->getSize().x/2.f,m_window->getSize().y/2.f});
    rect.setFillColor(sf::Color::Green);
    font.loadFromFile("data/Fonts/JetBrainsMono-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(window.getSize().y*0.05f);
    text.setFillColor(sf::Color::Red);
}

TestState::~TestState() {
    std::cout << "Test State goes out of scope" << std::endl;
}

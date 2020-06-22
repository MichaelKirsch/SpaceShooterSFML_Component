#pragma once
#include "Engine/StateMachine/State.h"
#include "StateMachine/Statemachine.h"
#include "MainGame.h"
#include <SFML/Network.hpp>

class
TestState : public State {
public:
    TestState(Statemachine* st,sf::RenderWindow& window);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;
    int score=0;
    std::string name="";
    void inputs() override;
    ~TestState();
private:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;
    sf::RenderWindow* m_window;
    sf::TcpSocket l_socket;
    const unsigned short PORT = 5000;
    const std::string IPADDRESS="2.56.99.66";//change to suit your needs
    bool connected = false;
    bool done = false;
    sf::Packet packet;
};



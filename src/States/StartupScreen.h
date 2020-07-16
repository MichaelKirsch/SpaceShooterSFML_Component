#pragma once
#include "StateMachine/State.h"
#include "MainGame.h"
#include "Entities/SpaceBackground.h"
#include "Entities/Sprite.h"
#include "Entities/SimpleText.h"
#include "ToggleList.h"
#include "support/color_loader.h"
#include <SQLiteCpp/SQLiteCpp.h>


class StartupScreen : public State {
public:
    StartupScreen(Statemachine* st, sf::RenderWindow& win);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    void inputs() override;

private:
    color_loader color_l;
    ToggleList list,colorschemes;
    SimpleText welcomwtext;
    Button buttontest,namefield;
    Sprite sprite;
    SpaceBackground background;
    sf::RenderWindow* m_window;
    std::string name="";
};



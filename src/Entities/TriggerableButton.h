#pragma once
#include "Entity.h"

class TriggerableButton : public Entity {
public:
    TriggerableButton();

    void start(std::string active_icon, std::string inactive_icon, sf::Color load_bar_col, float reset_time, bool active_at_start=true);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    void trigger();

private:
};



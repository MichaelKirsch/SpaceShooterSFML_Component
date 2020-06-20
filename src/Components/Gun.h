#pragma once
#include "Component.h"
#include "Entity.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace nlohmann;

struct Bullet
{
    sf::RectangleShape bullet_body;
    sf::Vector2f position;
    sf::Vector2f direction;
    float damage;
    float lifetime;
    float timer;
    float speed;
    bool active;
    bool checkTimer()
    {
        return timer<lifetime;
    }
    void update_timer(float deltatime)
    {
        timer+=deltatime;
    }
};

struct GunStats
{

    int firerate;
    float damage;
    std::string bullet_image_string;
    float bullet_speed;
    sf::Vector2f bullet_size;
    bool burstmode;
    float burstmode_pause;
    int burst_size;
    float spread;
};

class Gun : public Component{
public:
    Gun(Entity* owner);

    void update(float deltaTime) override;

    void lateUpdate(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    void loadGun(std::string gun_script);


private:
    sf::Vector2f position;
    GunStats c;
    sf::Texture bullet_texture;
    std::array<Bullet,20> bulletpool;
};



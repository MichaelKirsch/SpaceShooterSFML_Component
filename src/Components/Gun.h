#pragma once
#include "Component.h"
#include "Entity.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include "Hitbox.h"
#include "Health.h"

using namespace nlohmann;

struct Bullet
{
    Bullet(sf::Texture& tx,sf::Vector2f bullet_size,sf::Vector2f i_pos, sf::Vector2f i_direction,
            float i_damage,float i_lifetime, float i_speed)
    {
        damage = i_damage;
        timer=0.f;
        lifetime = i_lifetime;
        speed = i_speed;
        position = i_pos;
        direction = i_direction;
        bullet_body.setSize(bullet_size);
        bullet_body.setTexture(&tx);
        bullet_body.setPosition(i_pos);
    }
    sf::RectangleShape bullet_body;
    sf::Vector2f position;
    sf::Vector2f direction;
    float damage;
    float lifetime;
    float timer;
    float speed;
    bool active=true;
    bool checkTimer()
    {
        return timer<lifetime;
    }
    void update(float deltatime)
    {
        timer+=deltatime;
        position +=(direction*speed)*deltatime;
        bullet_body.setPosition(position);
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

    void draw(sf::RenderWindow &window) override;

    bool check_for_hitbox(std::shared_ptr<Hitbox> box,std::shared_ptr<Health> health);

    void loadGun(std::string gun_script,sf::RenderWindow& window);


    int getAmmo(){return ammo;};
    sf::Vector2f offset={0.f,0.f};
private:
    sf::Vector2f position;
    GunStats c;
    sf::Texture bullet_texture;
    std::vector<std::unique_ptr<Bullet>> bullet_pool;
    float last_fired=0.f;
    int ammo=0;
};



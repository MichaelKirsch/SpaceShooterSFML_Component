//
// Created by micha on 18.06.2020.
//

#include "Gun.h"

Gun::Gun(Entity *owner) : Component(owner) {

}

void Gun::update(float deltaTime) {
    position = owner->transform->getPosition()+offset;
    last_fired+=deltaTime;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(last_fired>float(1.f/c.firerate)&& ammo>0)
        {
            ammo--;
            bullet_pool.emplace_back(new Bullet(bullet_texture,c.bullet_size,position
                    ,{0.f,-1.f},c.damage,1.5f,c.bullet_speed));
            last_fired=0.f;
        }
    }
    for(auto& b:bullet_pool)
    {
        b->update(deltaTime);
    }


    for(auto it = std::begin(bullet_pool); it != std::end(bullet_pool); ) {
        auto& pr = *it;
        // ...
        if(!pr->checkTimer()) {
            it = bullet_pool.erase(it);
        } else {
            ++it;
        }
    }

}


void Gun::draw(sf::RenderWindow &window) {
    for(auto& b:bullet_pool)
        window.draw(b->bullet_body);
}

void Gun::loadGun(std::string gun_script) {
    json j;
    std::ifstream o(gun_script);
    o>>j;
    c.firerate = j.at("firerate");
    c.bullet_image_string = j.at("bullet_texture");
    c.bullet_speed = j.at("bulletspeed");
    c.damage = j.at("damage");
    c.bullet_size.x = j.at("bulletSizeX");
    c.bullet_size.y = j.at("bulletSizeY");
    c.spread = j.at("spread");
    c.burst_size = j.at("burst_size");
    c.burstmode_pause = j.at("burst_pause");
    bullet_texture.loadFromFile(c.bullet_image_string);
    ammo = j.at("ammo");
}

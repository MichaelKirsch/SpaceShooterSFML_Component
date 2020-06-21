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
        if(last_fired>float(1.f/c.firerate)&& current_ammo>0)
        {
            current_ammo--;
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
        if(!pr->checkTimer()|| !pr->active) {
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

void Gun::loadGun(std::string gun_script,sf::RenderWindow& window) {
    json j;
    std::ifstream o(gun_script);
    o>>j;
    c.firerate = j.at("firerate");
    c.bullet_image_string = j.at("bullet_texture");
    c.bullet_speed = j.at("bulletspeed");
    c.damage = j.at("damage");
    c.bullet_size.x = float(j.at("bulletSizeX"))* window.getSize().y;
    c.bullet_size.y = float(j.at("bulletSizeY"))* window.getSize().y;
    c.spread = j.at("spread");
    c.burst_size = j.at("burst_size");
    c.burstmode_pause = j.at("burst_pause");
    bullet_texture.loadFromFile(c.bullet_image_string);
    ammo_cap = j.at("ammo");
    current_ammo= ammo_cap;
}

bool Gun::check_for_hitbox(std::shared_ptr<Hitbox> box, std::shared_ptr<Health> health) {
    for(auto& b:bullet_pool)
        if(box->hitbox.getGlobalBounds().intersects(b->bullet_body.getGlobalBounds()))
        {
            b->active=false;
            health->inflictDamageRaw(b->damage);
        }
}



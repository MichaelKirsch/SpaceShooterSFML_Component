//
// Created by micha on 18.06.2020.
//

#include "Gun.h"

Gun::Gun(Entity *owner) : Component(owner) {

}

void Gun::update(float deltaTime) {
    position = owner->transform->getPosition();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        std::cout << "FIRE!"<< c.bullet_image_string << std::endl;
    }
}

void Gun::lateUpdate(float deltaTime) {

}

void Gun::draw(sf::RenderWindow &window) {

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

}

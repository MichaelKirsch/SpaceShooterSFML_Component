//
// Created by micha on 18.06.2020.
//

#include "Animation.h"

Animation::Animation(Entity *owner) : Component(owner) {

}

void Animation::update(float deltaTime) {
    timer+=deltaTime;
    if(timer>jump_time)
    {
        timer =0.f;
        current_image++;
        if(current_image>=amount_pictures)
            current_image =0;
        int y = current_image/grid.x;
        int x = current_image%grid.x;
        sprite->getRect().setTextureRect(sf::IntRect(x*picture_size.x,y*picture_size.y,picture_size.x,picture_size.y));
    }
}

void Animation::draw(sf::RenderWindow &window) {

}

void Animation::start(std::shared_ptr<SimpleSprite> sprite_to_act_on) {
    sprite = sprite_to_act_on;
    m_shape = &sprite->getRect();
    textPtrSprite = &sprite->getTexture();
}

void Animation::configureTextureAtlas(std::string texture_atlas, sf::Vector2u i_grid, float i_jumpTime, int i_cutoff_end) {
    cutoff_end = i_cutoff_end;
    jump_time = i_jumpTime;
    grid = i_grid;
    amount_pictures=(grid.x*grid.y)-i_cutoff_end;
    textPtrSprite->loadFromFile(texture_atlas);
    picture_size = {float(textPtrSprite->getSize().x/grid.x),float(textPtrSprite->getSize().y/grid.y)};
}

void Animation::start(sf::Texture &texture, sf::RectangleShape &shape) {
    m_shape = &shape;
    textPtrSprite = &texture;
}


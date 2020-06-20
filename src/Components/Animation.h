#pragma once
#include "Component.h"
#include "Entity.h"
#include "SimpleSprite.h"
#include <iostream>

class Animation : public Component{
public:
    Animation(Entity* owner);

    void start(std::shared_ptr<SimpleSprite> sprite_to_act_on);

    void configureTextureAtlas(std::string texture_atlas, sf::Vector2u grid,float i_jumpTime,int i_cutoff_end =0);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

private:
    std::shared_ptr<SimpleSprite> sprite;
    sf::Texture* textPtrSprite;
    sf::Vector2f single_texture_size;
    float jump_time=0.f;
    float timer=0.f;
    int current_image=0;
    int amount_pictures=0;
    sf::Vector2u grid;
    sf::Vector2f picture_size;
    int cutoff_end=0;
};



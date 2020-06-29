#pragma once
#include "Entity.h"
#include "SimpleSprite.h"
#include "Animation.h"

class Sprite : public Entity {
public:
    Sprite(){
        body = AddComponent<SimpleSprite>();
        animation = AddComponent<Animation>();
    };
    std::shared_ptr<SimpleSprite> body;
    std::shared_ptr<Animation> animation;
private:
};



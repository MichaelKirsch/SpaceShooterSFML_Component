#pragma once
#include "Entity.h"
#include "Text.h"

class SimpleText : public Entity{
public:
    SimpleText(){
        text = AddComponent<Text>();
    };

    std::shared_ptr<Text> text;
private:
};



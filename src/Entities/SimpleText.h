#pragma once
#include "Entity.h"
#include "Text.h"
#include "support/color_loader.h"

class SimpleText : public Entity{
public:
    SimpleText(){
        text = AddComponent<Text>();
    };


    void highlight(bool status)
    {
        highlighted = status;
        update_status = true;
    };

    void update(float deltaTime) override {
        Entity::update(deltaTime);
        if(update_status)
        {
            update_status = false;
            if(colorLoader!= nullptr)
            {
                if(highlighted)
                {
                    text->setColor(colorLoader->getColor(color_loader::texthighlight));
                }
                else
                {
                    text->setColor(colorLoader->getColor(color_loader::text));
                }
            }
        }
    }


    void setColorLoader(color_loader* loader)
    {
        colorLoader = loader;
        text->setColor(loader->getColor(color_loader::text));
    };

    std::shared_ptr<Text> text;
private:
    bool update_status = false;
    bool highlighted = false;
    color_loader*colorLoader = nullptr;
};



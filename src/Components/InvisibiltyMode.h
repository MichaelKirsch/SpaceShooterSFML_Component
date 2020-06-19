#pragma once
#include "Component.h"
#include "Entity.h"
#include "Aura.h"

class InvisibiltyMode : public Component{
public:
    InvisibiltyMode(Entity* owner);

    void start(float time);
    void trigger();
    void addTime(float time);
    void update(float deltaTime) override;
    bool isInvisible();
private:
    float timer=0.f;
    float max_Time=0.f;
    std::shared_ptr<Aura> ownerAura;
};



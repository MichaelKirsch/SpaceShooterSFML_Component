#pragma once
#include "Component.h"
#include "Entity.h"

class KeyboardMover : public Component
{
public:
    KeyboardMover(Entity* owner);

    void update(float deltaTime) override;

private:
    float speed=10.f;
};



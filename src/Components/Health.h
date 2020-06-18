#pragma once
#include "Component.h"
#include "Entity.h"

class Health : public Component{
public:
    Health(Entity* owner);

    void start(float i_maxHealth);

    void lateUpdate(float deltaTime) override;

    void rechargeRaw(float amount);

    void rechargePercent(float percent);

    bool isAlife();

    float getHealthRaw();

    int getHealthPercent();

    bool inflictDamagePercent(float percent);

    bool inflictDamageRaw(float raw_damage);

private:
    float maxHealth=0.f;
    float health=0.f;
    bool alive=true;
};



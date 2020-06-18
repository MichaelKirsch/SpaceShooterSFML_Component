#include "Health.h"

Health::Health(Entity *owner) : Component(owner) {

}

void Health::start(float i_maxHealth) {
    maxHealth = i_maxHealth;
    health= maxHealth;
}

void Health::lateUpdate(float deltaTime) {
    if(health<0.f)
        alive=false;
}

void Health::rechargeRaw(float amount) {
    health+=amount;
    if(health>maxHealth)
        health = maxHealth;
}

void Health::rechargePercent(float percent) {
    float one_perc = maxHealth/100.f;
    float amountRaw=one_perc*percent;
    rechargeRaw(amountRaw);
}

bool Health::isAlife() {
    return health>0.f;
}

float Health::getHealthRaw() {
    return health;
}

int Health::getHealthPercent() {
    float one_perc = 100.f/maxHealth;
    return static_cast<int>(one_perc*health);
}

bool Health::inflictDamagePercent(float percent) {
    float one_perc = maxHealth/100.f;
    health-=one_perc*percent;

    if(health <= 0.f){
        health = 0.f;
        alive = false;
    }


    return health<=0.f;
}

bool Health::inflictDamageRaw(float raw_damage) {
    health-=raw_damage;

    if(health <= 0.f){
        health = 0.f;
        alive = false;
    }

    return health<=0.f;
}

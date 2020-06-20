//
// Created by micha on 10.06.2020.
//

#include "Entity.h"


void Entity::awake() {
    for(int i = components.size() - 1; i >= 0; i--)
        if(components[i]->active)
            components[i]->awake();
}

void Entity::start() {
    for(int i = components.size() - 1; i >= 0; i--)
        if(components[i]->active)
            components[i]->start();
}

void Entity::update(float deltaTime) {
    for(int i = components.size() - 1; i >= 0; i--)
        if(components[i]->active)
            components[i]->update(deltaTime);
}

void Entity::lateUpdate(float deltaTime) {
    for(int i = components.size() - 1; i >= 0; i--)
        if(components[i]->active)
            components[i]->lateUpdate(deltaTime);
}

void Entity::draw(sf::RenderWindow &window) {
    for(int i = components.size() - 1; i >= 0; i--)
        if(components[i]->active)
            components[i]->draw(window);
}

void Entity::respawn() {

}

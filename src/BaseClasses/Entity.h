#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"
#include <vector>
#include <memory>
#include "Transform.h"
class Entity {
public:
    Entity(){
        transform = AddComponent<Transform>();
    };

    virtual void awake();

    virtual void start();// Start is called after Awake method. Use to initialise variables.

    virtual void update(float deltaTime);

    virtual void lateUpdate(float deltaTime);

    virtual void draw(sf::RenderWindow& window);

    template <typename T> std::shared_ptr<T> AddComponent() // 1
    {
        // This ensures that we only try to add a class the derives
        // from Component. This is tested at compile time.
        static_assert(std::is_base_of<Component, T>::value,"Must be derived from Component");

        // Check that we don't already have a component of this type.
        for (auto& exisitingComponent : components)
        {
            // Currently we prevent adding the same component twice.
            // This may be something we will change in future.
            //if (std::dynamic_pointer_cast<T>(exisitingComponent))
            //{
            //    return std::dynamic_pointer_cast<T>(exisitingComponent); // 2
            //}
        }

        // The object does not have this component so we create it and
        // add it to our list.



        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        components.push_back(newComponent);

        return newComponent;
    };

    template <typename T> std::shared_ptr<T> GetComponent()
    {
        static_assert(std::is_base_of<Component, T>::value,"T must derive from Component");

        // Check that we don't already have a component of this type.
        for (auto& exisitingComponent : components)
        {
            if (std::dynamic_pointer_cast<T>(exisitingComponent))
            {
                return std::dynamic_pointer_cast<T>(exisitingComponent);
            }
        }
        throw std::runtime_error("Cant get Component");
    };

    std::shared_ptr<Transform> transform;

private:
    std::vector<std::shared_ptr<Component>> components;
};



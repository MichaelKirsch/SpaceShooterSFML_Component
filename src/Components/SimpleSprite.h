#pragma once
#include "Component.h"
#include "Entity.h"

class SimpleSprite : public Component{
public:
    SimpleSprite(Entity* owner);
// Loads a sprite from file.
    void load(const std::string& filePath);

    // We override the draw method so we can draw our sprite.
    void draw(sf::RenderWindow& window) override;

    void lateUpdate(float deltaTime) override;

    sf::Vector2f getSize(){
        return sprite.getSize();
    }

    void setSize(sf::Vector2f newSize)
    {
        sprite.setSize(newSize);
    }

    sf::Texture& getTexture()
    {
        return texture;
    }

    void setOffset(sf::Vector2f offset_to_owner);

    sf::Vector2f getOffset();

    void update(float deltaTime) override;

private:
    sf::Vector2f offset={0.f,0.f};
    sf::Texture texture;
    sf::RectangleShape sprite;
};



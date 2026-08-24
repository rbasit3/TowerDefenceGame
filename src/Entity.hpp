#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Entity {
protected:
    Vector2f position;
    Texture texture;
    Sprite sprite;

public:
    // SFML 3 requires texture to be loaded immediately
    Entity(float x, float y, const string& imgPath) 
        : position(x, y), texture(imgPath), sprite(texture) 
    {
        // Center the origin for easy placement
        sprite.setOrigin({texture.getSize().x / 2.0f, texture.getSize().y / 2.0f});
        sprite.setPosition(position);
    }

    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render(RenderWindow& window) = 0;
    // Getter for coordinates
    Vector2f getPosition() const { return position; }
};
#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::Vector2f position;
    bool active;

public:
    Entity(float x, float y);
    //causes a change in entity's state. will bw different for every subclass
    virtual void Move(float deltaTime) = 0;
    //draws the entity to the window. also diff for very class
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void attack() = 0;
    virtual void takeDamage(float amount) = 0;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    bool getActive() const;
    void setActive(bool active);
    virtual ~Entity();
};
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
    virtual void update(float deltaTime) = 0;
    //draws the entity to the window. also diff for very class
    virtual void render(sf::RenderWindow& window) = 0;
    //works kinda the same way for all entities
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    bool getActive() const;
    void setActive(bool active);
    virtual ~Entity();
};
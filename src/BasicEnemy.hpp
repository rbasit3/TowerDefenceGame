#pragma once

#include "Enemy.hpp"
//inherited attributes
    /*speed
    health
    maxHealth
    damage
    reward*/
class BasicEnemy : public Enemy
{
private:
    sf::CircleShape shape;

public:
    BasicEnemy(float x, float y);

    void attack() override;
    void Move(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    ~BasicEnemy() override = default;
};
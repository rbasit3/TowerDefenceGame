#pragma once

#include "Enemy.hpp"

// Inherited attributes:
// speed, health, maxHealth, damage and reward
class TankEnemy : public Enemy
{
private:
    sf::CircleShape shape;

public:
    TankEnemy(float x, float y);

    void attack() override;
    void Move(float deltaTime) override;
    void takeDamage(float amount) override;
    void render(sf::RenderWindow& window) override;

    ~TankEnemy() override = default;
};
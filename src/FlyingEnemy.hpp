#pragma once

#include "Enemy.hpp"

// Inherited attributes:
// speed, health, maxHealth, damage and reward
class FlyingEnemy : public Enemy
{
private:
    sf::CircleShape shape;
    sf::Vector2f exitPosition;

public:
    FlyingEnemy(float x, float y, const sf::Vector2f& exitPosition);

    void attack() override;
    void Move(float deltaTime) override;
    void takeDamage(float amount) override;
    void render(sf::RenderWindow& window) override;

    ~FlyingEnemy() override = default;
};
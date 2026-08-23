#pragma once

#include "Enemy.hpp"

// Inherited attributes:
// speed, health, maxHealth, damage and reward
class RegeneratingEnemy : public Enemy
{
private:
    sf::CircleShape shape;
    float regenerationRate;

    void regenerate(float deltaTime);

public:
    RegeneratingEnemy(float x, float y);

    void attack() override;
    void Move(float deltaTime) override;
    void takeDamage(float amount) override;
    void render(sf::RenderWindow& window) override;

    float getRegenerationRate() const;
    void setRegenerationRate(float regenerationRate);

    ~RegeneratingEnemy() override = default;
};
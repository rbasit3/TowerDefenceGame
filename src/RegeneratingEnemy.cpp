#include "RegeneratingEnemy.hpp"
#include <algorithm>

RegeneratingEnemy::RegeneratingEnemy(float x, float y)
    : Enemy(x, y, 150.f, 70.f, 1, 25),
      shape(27.f),
      regenerationRate(10.f)
{
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Magenta);
}

void RegeneratingEnemy::attack()
{
    // Game subtracts getDamage() from the player's lives.
    setActive(false);
}

void RegeneratingEnemy::Move(float deltaTime)
{
    if (!getActive())
    {
        return;
    }

    regenerate(deltaTime);

    position.x += getSpeed() * deltaTime;
    shape.setPosition(position);
}

void RegeneratingEnemy::regenerate(float deltaTime)
{
    if (getHealth() < getMaxHealth())
    {
        float newHealth = getHealth() + regenerationRate * deltaTime;
        setHealth(std::min(newHealth, getMaxHealth()));
    }
}

void RegeneratingEnemy::takeDamage(float amount)
{
    Enemy::takeDamage(amount);
}

void RegeneratingEnemy::render(sf::RenderWindow& window)
{
    if (!getActive())
    {
        return;
    }

    window.draw(shape);
}

float RegeneratingEnemy::getRegenerationRate() const
{
    return regenerationRate;
}

void RegeneratingEnemy::setRegenerationRate(float regenerationRate)
{
    if (regenerationRate >= 0.f)
    {
        this->regenerationRate = regenerationRate;
    }
}
#include "FlyingEnemy.hpp"
#include <cmath>

FlyingEnemy::FlyingEnemy(float x, float y,
                         const sf::Vector2f& exitPosition)
    : Enemy(x, y, 75.f, 120.f, 1, 15),
      shape(22.f, 3),
      exitPosition(exitPosition)
{
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Cyan);
}

void FlyingEnemy::attack()
{
    // Game subtracts getDamage() from the player's lives.
    setActive(false);
}

void FlyingEnemy::Move(float deltaTime)
{
    if (!getActive())
    {
        return;
    }

    sf::Vector2f direction = exitPosition - position;

    float distance = std::sqrt(direction.x * direction.x +
                               direction.y * direction.y);

    if (distance == 0.f)
    {
        return;
    }

    float movementDistance = getSpeed() * deltaTime;

    if (movementDistance >= distance)
    {
        position = exitPosition;
    }
    else
    {
        direction.x /= distance;
        direction.y /= distance;
        position += direction * movementDistance;
    }

    shape.setPosition(position);
}

void FlyingEnemy::takeDamage(float amount)
{
    Enemy::takeDamage(amount);
}

void FlyingEnemy::render(sf::RenderWindow& window)
{
    if (!getActive())
    {
        return;
    }

    window.draw(shape);
}
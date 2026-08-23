#include "FastEnemy.hpp"

FastEnemy::FastEnemy(float x, float y)
    : Enemy(x, y, 40.f, 200.f, 1, 15),
      shape(20.f)
{
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Yellow);
}

void FastEnemy::attack()
{
    // Game subtracts getDamage() from the player's lives.
    setActive(false);
}

void FastEnemy::Move(float deltaTime)
{
    if (!getActive())
    {
        return;
    }

    position.x += getSpeed() * deltaTime;
    shape.setPosition(position);
}

void FastEnemy::takeDamage(float amount)
{
    Enemy::takeDamage(amount);
}

void FastEnemy::render(sf::RenderWindow& window)
{
    if (!getActive())
    {
        return;
    }

    window.draw(shape);
}
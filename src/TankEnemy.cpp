#include "TankEnemy.hpp"

TankEnemy::TankEnemy(float x, float y)
    : Enemy(x, y, 500.f, 40.f, 1, 30),
      shape(35.f)
{
    shape.setPosition(position);
    shape.setFillColor(sf::Color(0, 100, 0));
}

void TankEnemy::attack()
{
    // Game subtracts getDamage() from the player's lives.
    setActive(false);
}

void TankEnemy::Move(float deltaTime)
{
    if (!getActive())
    {
        return;
    }

    position.x += getSpeed() * deltaTime;
    shape.setPosition(position);
}

void TankEnemy::takeDamage(float amount)
{
    Enemy::takeDamage(amount);
}

void TankEnemy::render(sf::RenderWindow& window)
{
    if (!getActive())
    {
        return;
    }

    window.draw(shape);
}
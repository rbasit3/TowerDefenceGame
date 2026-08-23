#include "BasicEnemy.hpp"

BasicEnemy::BasicEnemy(float x, float y)
    : Enemy(x, y, 100.f, 100.f, 1, 10),
      shape(25.f)
{
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Red);
}

void BasicEnemy::attack()
{
    // Game subtracts getDamage() from the player's lives.
    setActive(false);
}

void BasicEnemy::Move(float deltaTime)
{
    if (!getActive())
    {
        return;
    }

    position.x += getSpeed() * deltaTime;
    shape.setPosition(position);
}

void BasicEnemy::render(sf::RenderWindow& window)
{
    if (!getActive())
    {
        return;
    }

    window.draw(shape);
}
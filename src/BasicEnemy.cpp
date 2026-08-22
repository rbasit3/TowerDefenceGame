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
    // The Game class will subtract getDamage() from the player's lives.
    // The enemy becomes inactive after attacking the base.
    setActive(false);
}

void BasicEnemy::Move(float deltaTime)
{
    if (!getActive())
    {
        return;
    }

    position.x += speed * deltaTime;
    shape.setPosition(position);
}

void BasicEnemy::takeDamage(float amount)
{
    Enemy::takeDamage(amount);

    if (isDead())
    {
        setActive(false);
    }
}

void BasicEnemy::render(sf::RenderWindow& window)
{
    if (getActive())
    {
        window.draw(shape);
    }
}
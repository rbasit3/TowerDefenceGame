#include "Game.hpp"

Game::Game()
{
    // Visible path
    //rectangle path
    path.setSize({1280.f, 120.f});
    path.setPosition({0.f, 300.f});
    path.setFillColor(sf::Color(170, 120, 70));

    // Temporary enemy
    //red dot for enemy
    enemy.setRadius(25.f);
    enemy.setPosition({0.f, 335.f});
    enemy.setFillColor(sf::Color::Red);

    enemySpeed = 100.f;
}

//moves the enemy from left to right
///consistent speed
void Game::update(float deltaTime)
{
    enemy.move({enemySpeed * deltaTime, 0.f});

    // Restart the enemy after it reaches the end
    if (enemy.getPosition().x > 1280.f)
    {
        enemy.setPosition({0.f, 335.f});
    }
}

//draws path and enemy to the window
void Game::render(sf::RenderWindow& window)
{
    window.draw(path);
    window.draw(enemy);
}
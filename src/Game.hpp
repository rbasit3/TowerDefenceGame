#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RectangleShape path;
    sf::CircleShape enemy;

    float enemySpeed;

public:
    Game();

    void update(float deltaTime);
    void render(sf::RenderWindow& window);
};
#pragma once

#include <SFML/Graphics.hpp>
#include "Button.hpp"

enum class GameState { 
    MENU,
    PLAY,
    ACHIEVEMENTS,
    INSTRUCTIONS,
    UPGRADES,
    SETTINGS
};

class Menu 
{
private:
    // Background
    sf::Texture bgTexture; 
    sf::Sprite bgSprite; 

    // Button pointers using simple raw pointers
    Button* playButton;
    Button* achievementsButton;
    Button* instructionsButton;
    Button* upgradesButton;
    Button* settingsButton;

public:
    Menu();
    ~Menu(); // Destructor to clean up raw pointers

    void update(const sf::RenderWindow& window); 
    void render(sf::RenderWindow& window); 
    
    GameState handleClick(sf::Vector2f mousePos); 
};
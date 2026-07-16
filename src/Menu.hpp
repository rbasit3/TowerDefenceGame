#pragma once //reads the file once

#include <SFML/Graphics.hpp>
enum class GameState { // list of named values that will store current game state
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
    sf::Texture bgTexture; //stores the image
    sf::Sprite bgSprite; // displayes the image

    // Buttons
    sf::Texture playTexture;
    sf::Sprite playSprite;

    sf::Texture achievementsTexture;
    sf::Sprite achievementsSprite;

    sf::Texture instructionsTexture;
    sf::Sprite instructionsSprite;

    sf::Texture upgradesTexture;
    sf::Sprite upgradesSprite;

    sf::Texture settingsTexture;
    sf::Sprite settingsSprite;

   // helper function for button hover effects
    void handleHover(sf::Sprite& sprite, sf::Vector2f originalScale, sf::Vector2f hoverScale, sf::Vector2f mousePos);

public:
    Menu();

    void update(const sf::RenderWindow& window); //gets mouse pos,check hover,button size and color
    void render(sf::RenderWindow& window); //draws everything
    
    
    GameState handleClick(sf::Vector2f mousePos); //checks which button is clicked and then returns the named value( current state) to a current state variable
};
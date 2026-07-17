#include "Menu.hpp"
#include <iostream>

using namespace std;


Menu::Menu()    
    : bgTexture("assets/menu_background.png"),
      bgSprite(bgTexture),

      playTexture("assets/ui/play_menu.png"),
      playSprite(playTexture),

      achievementsTexture("assets/ui/achievements_menu.png"),
      achievementsSprite(achievementsTexture),

      instructionsTexture("assets/ui/instructions_menu.png"),
      instructionsSprite(instructionsTexture),

      upgradesTexture("assets/ui/upgrades_menu.png"),
      upgradesSprite(upgradesTexture),

      settingsTexture("assets/ui/settings_menu.png"),
      settingsSprite(settingsTexture)
{
    
    // playSprite.setScale({1.2f, 1.2f});
    // achievementsSprite.setScale({0.6f, 0.7f});
    // instructionsSprite.setScale({0.6f, 0.7f});
    // upgradesSprite.setScale({0.6f, 0.6f});
    // settingsSprite.setScale({0.7f, 0.7f});

    //sets the sprites position
    bgSprite.setPosition({0.f, 0.f});
    playSprite.setPosition({538.f, 443.f});
    achievementsSprite.setPosition({516.f, 569.f});
    instructionsSprite.setPosition({519.f, 502.f});
    upgradesSprite.setPosition({516.f, 640.f});
    settingsSprite.setPosition({1138.f, 613.f});
    
}

void Menu::update(const sf::RenderWindow& window)
{
   
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //gets current mouse position
    handleHover(playSprite, {1.33f, 1.25f}, {1.34f, 1.27f}, mousePos);
    handleHover(achievementsSprite, {0.6f, 0.7f}, {0.61f, 0.73f}, mousePos);
    handleHover(instructionsSprite, {0.6f, 0.71f}, {0.61f, 0.74f}, mousePos);
    handleHover(upgradesSprite, {0.68f, 0.68f}, {0.689f, 0.71f}, mousePos);
    handleHover(settingsSprite, {0.68f, 0.68f}, {0.69f, 0.69f}, mousePos);
}

void Menu::handleHover(sf::Sprite& sprite, sf::Vector2f originalScale, sf::Vector2f hoverScale, sf::Vector2f mousePos)
{
    // Check if the mouse is touching the button
    if (sprite.getGlobalBounds().contains(mousePos)) //getglobalbounds sets the rectangle around the sprite and contains check if the mouse is inside it
    {
        sprite.setScale(hoverScale); //makes button larger
        sprite.setColor(sf::Color(255, 235, 150)); // sets color for hover
    }
    else
    {
        sprite.setScale(originalScale);
        sprite.setColor(sf::Color::White); 
    }
}


void Menu::render(sf::RenderWindow& window) // draws everything. requires window.display()
{
    window.draw(bgSprite);

    window.draw(playSprite);
    window.draw(achievementsSprite);
    window.draw(instructionsSprite);
    window.draw(upgradesSprite);

    window.draw(settingsSprite);
}

GameState Menu::handleClick(sf::Vector2f mousePos) //checks button clicking and returns the current state
{
    if (playSprite.getGlobalBounds().contains(mousePos))
    {
        cout << "Play button clicked!" << endl;
        return GameState::PLAY;
    }
    
    if (achievementsSprite.getGlobalBounds().contains(mousePos))
    {
        cout << "Achievements button clicked!" << endl;
        return GameState::ACHIEVEMENTS;
    }
    
    if (instructionsSprite.getGlobalBounds().contains(mousePos))
    {
        cout << "Instructions button clicked!" << endl;
        return GameState::INSTRUCTIONS;
    }
    
    if (upgradesSprite.getGlobalBounds().contains(mousePos))
    {
        cout << "Upgrades button clicked!" << endl;
        return GameState::UPGRADES;
    }
    
    if (settingsSprite.getGlobalBounds().contains(mousePos))
    {
        cout << "Settings button clicked!" << endl;
        return GameState::SETTINGS;
    }

    // if nothing was clicked it stays on the menu
    return GameState::MENU; 
}
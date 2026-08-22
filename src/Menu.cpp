#include "Menu.hpp"
#include <iostream>

using namespace std;

Menu::Menu() :bgTexture("assets/menu_background.png"),  bgSprite(bgTexture)   
{
    // Load background image[cite: 4]
    bgSprite.setPosition({0.f, 0.f});

    // Initialize buttons using new and your original coordinates/scales[cite: 4]
    playButton = new Button("assets/ui/play_menu.png", {538.f, 443.f}, {1.33f, 1.25f}, {1.34f, 1.27f});
    achievementsButton = new Button("assets/ui/achievements_menu.png", {516.f, 569.f}, {0.6f, 0.7f}, {0.61f, 0.73f});
    instructionsButton = new Button("assets/ui/instructions_menu.png", {519.f, 502.f}, {0.6f, 0.71f}, {0.61f, 0.74f});
    upgradesButton = new Button("assets/ui/upgrades_menu.png", {516.f, 640.f}, {0.68f, 0.68f}, {0.689f, 0.71f});
    settingsButton = new Button("assets/ui/settings_menu.png", {1138.f, 613.f}, {0.68f, 0.68f}, {0.69f, 0.69f});
}

Menu::~Menu() 
{
    // Delete raw pointers to free memory when the menu is destroyed
    delete playButton;
    delete achievementsButton;
    delete instructionsButton;
    delete upgradesButton;
    delete settingsButton;
}

void Menu::update(const sf::RenderWindow& window)
{
    // Get current mouse position[cite: 4]
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); 
    
    // Update all buttons with simple function calls
    playButton->update(mousePos);
    achievementsButton->update(mousePos);
    instructionsButton->update(mousePos);
    upgradesButton->update(mousePos);
    settingsButton->update(mousePos);
}

void Menu::render(sf::RenderWindow& window) 
{
    window.draw(bgSprite);

    // Draw all buttons to the screen[cite: 4]
    playButton->render(window);
    achievementsButton->render(window);
    instructionsButton->render(window);
    upgradesButton->render(window);
    settingsButton->render(window);
}

GameState Menu::handleClick(sf::Vector2f mousePos) 
{
    // Check which button was clicked and return the corresponding state[cite: 4]
    if (playButton->isClicked(mousePos))
    {
        cout << "Play button clicked!" << endl;
        return GameState::PLAY;
    }
    
    if (achievementsButton->isClicked(mousePos))
    {
        cout << "Achievements button clicked!" << endl;
        return GameState::ACHIEVEMENTS;
    }
    
    if (instructionsButton->isClicked(mousePos))
    {
        cout << "Instructions button clicked!" << endl;
        return GameState::INSTRUCTIONS;
    }
    
    if (upgradesButton->isClicked(mousePos))
    {
        cout << "Upgrades button clicked!" << endl;
        return GameState::UPGRADES;
    }
    
    if (settingsButton->isClicked(mousePos))
    {
        cout << "Settings button clicked!" << endl;
        return GameState::SETTINGS;
    }

    // Stay on menu if nothing was clicked[cite: 4]
    return GameState::MENU; 
}
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    
    sf::Vector2f normalScale;
    sf::Vector2f hoverScale;
    sf::Color normalColor;
    sf::Color hoverColor;

public:
  
    // Constructor sets up the button's image, position, and sizing
    Button(const std::string& texturePath, sf::Vector2f position, sf::Vector2f normalScale, sf::Vector2f hoverScale);

    // Updates hover effects based on current mouse position
    void update(sf::Vector2f mousePos);

    // Draws the button to the screen
    void render(sf::RenderWindow& window) const;

    // Returns true if the given mouse position is inside the button
    bool isClicked(sf::Vector2f mousePos) const;
    
    // Allows changing position later if needed
    void setPosition(sf::Vector2f position);
};
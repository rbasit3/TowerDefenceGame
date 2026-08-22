#include "Button.hpp"
#include <iostream>



Button::Button(const std::string& texturePath, sf::Vector2f position, sf::Vector2f normalScale, sf::Vector2f hoverScale)
    : texture(texturePath),
      sprite(texture),
      normalScale(normalScale),
      hoverScale(hoverScale),
      normalColor(sf::Color::White),
      hoverColor(sf::Color(255, 235, 150)) //in sfml 3 it requires a default consttructor for sf::sprite
{
    // Load the texture from the provided file path
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load texture at " << texturePath << std::endl;
    }
    
    // Apply texture and initial settings to the sprite
    sprite.setColor(normalColor);
    sprite.setPosition(position);
    sprite.setScale(normalScale);
    
}

void Button::update(sf::Vector2f mousePos) 
{
    // Check if the mouse is touching the button
    if (sprite.getGlobalBounds().contains(mousePos)) 
    {
        sprite.setScale(hoverScale); // Make button larger
        sprite.setColor(hoverColor); // Apply hover color
    } 
    else 
    {
        sprite.setScale(normalScale); // Revert to normal size
        sprite.setColor(normalColor); // Revert to normal color
    }
}

void Button::render(sf::RenderWindow& window) const 
{
    window.draw(sprite);
}

bool Button::isClicked(sf::Vector2f mousePos) const 
{
    return sprite.getGlobalBounds().contains(mousePos);
}

void Button::setPosition(sf::Vector2f position) 
{
    sprite.setPosition(position);
}
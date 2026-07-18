#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include <iostream>
#include "Game.hpp"
int main()
{
    //sets the window size (preferably 1280 x 720 for now)
    sf::RenderWindow window(
        sf::VideoMode({1280, 720}),
        "Tower Defense"
    );

    Menu menu; // constructor loads textures
    Game game;
    sf::Clock clock;
    
    GameState currentState = GameState::MENU; // MENU state

    while (window.isOpen()) //main game loop
    {
        float deltaTime = clock.restart().asSeconds();
        while (const auto event = window.pollEvent()) //pollevent() checks if ltr ANYTHING happens i.e click,press
        {
            if (event->is<sf::Event::Closed>()) // as you click the Cross (X) button, it exits. 
            {
                window.close();
            }

            
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) // check for mouse clicks. (smth that SFML 3.0.2 requires)
            {
               
                if (mousePressed->button == sf::Mouse::Button::Left) // only check if it is a left click
                {
                    
                    sf::Vector2f mousePos = window.mapPixelToCoords(mousePressed->position);// it converts the click pixel to standard coordinates

                    
                    if (currentState == GameState::MENU) // only process menu clicks if we are actually in the MENU state. It doesnt allow to click elsewhere 
                    {
                        currentState = menu.handleClick(mousePos); //passes the click location to your menuu
                    }
                }
            }
        }

        window.clear(); //wipes old data

        
        switch (currentState) //updates the screen basically (60 times for now)
        {
            case GameState::MENU:
                menu.update(window); //hover effects
                menu.render(window);//draws the mnu
                break;

            case GameState::PLAY:
                // testing 
                window.clear(sf::Color(70, 150, 70));
                game.update(deltaTime);
                game.render(window);
                break;

            case GameState::ACHIEVEMENTS:
                window.clear(sf::Color::Green);// testing 
                break;

            case GameState::INSTRUCTIONS:
                window.clear(sf::Color::Red);// testing 
                break;

            case GameState::UPGRADES:
                window.clear(sf::Color::Yellow);// testing 
                break;

            case GameState::SETTINGS:
                window.clear(sf::Color::Cyan);// testing 
                break;
        }

        window.display();// display everything changed yet
    } 

    return 0;
}
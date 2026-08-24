#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "HUD.hpp"
#include "Enemy.hpp"

class GameMechanics {
private:
    sf::Texture mapTexture;
    sf::Sprite mapSprite;

    int currentGold;

    static const int CELL_SIZE = 50;
    
    int levelNumber;
    int numBuildSpots;
    sf::Vector2f* allowedBuildSpots; 

    
    bool isHoveringValidSpot;
    sf::Vector2f currentHoverPos;
    
    sf::CircleShape hoverRadiusCircle;
    sf::VertexArray boundedGridLines; // Stores the cut-off grid lines

    bool isCellSelected;
    sf::Vector2f selectedCellPos;

    float hoverRadius;
    float gridLineRadius;

    int maxTowers;
    Tower** activeTowers; //tower ki logic kinda

    void loadBuildSpots();

    HUD hud;

    Enemy* testEnemy; //enemy ki logic

    sf::Vector2f* levelPath;
    int pathLength;
    

public:
    GameMechanics();
    ~GameMechanics(); 

    void update(float deltaTime, sf::Vector2f mousePos);
    void render(sf::RenderWindow& window);
    void handleMouseClick(sf::Vector2f mousePos);
    
    bool isSpotFree(float checkX, float checkY) const;

    void modifyGold(int amount); //Helper function to globally add or spend gold
    
};
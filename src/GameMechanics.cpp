#include "GameMechanics.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
using namespace sf;

GameMechanics::GameMechanics() 
    : mapTexture("assets/levels/level_1.png"),
      mapSprite(mapTexture),
      levelNumber(1),
      numBuildSpots(0),
      allowedBuildSpots(nullptr),
      isHoveringValidSpot(false),
      isCellSelected(false), 
      boundedGridLines(PrimitiveType::Lines)
{
    mapSprite.setScale({1280.f / 1227.f, 720.f / 685.f});

    // SETUP CIRCULAR HOVER 
    hoverRadius = CELL_SIZE * 1.0f; 
    gridLineRadius = CELL_SIZE * 1.5f;
    hoverRadiusCircle.setRadius(hoverRadius);
    hoverRadiusCircle.setOrigin({hoverRadius, hoverRadius}); // Center the circle
    
    // Negative thickness draws the border INWARD, creating an inner shadow effect
    hoverRadiusCircle.setOutlineThickness(-1.5f); 

    // Initialize raw pointer array for active towers
    maxTowers = 20;
    activeTowers = new Tower*[maxTowers];
    for (int i = 0; i < maxTowers; i++) {
        activeTowers[i] = nullptr; // Default all slots to empty
    }

    currentGold = 0; // Initialize at 0
    modifyGold(150); 
    loadBuildSpots();



    //enemy path logic

   ifstream pFile("assets/TextFiles/level_1_path.txt");
    if (pFile.is_open()) {
        pFile >> pathLength;
        levelPath = new sf::Vector2f[pathLength];
        for (int i = 0; i < pathLength; i++) {
            pFile >> levelPath[i].x >> levelPath[i].y;
        }
        pFile.close();
    }

    // Now spawn the enemy using the path data!
    if (levelPath != nullptr && pathLength > 0) {
        testEnemy = new Enemy6(levelPath[0].x, levelPath[0].y, levelPath, pathLength);
    }
}

void GameMechanics::modifyGold(int amount) 
{
    // Safely add or subtract gold, and instantly sync it to the UI
    currentGold += amount;
    hud.updateGold(currentGold);
}

GameMechanics::~GameMechanics() 
{
    // Clean up grid memory
    if (allowedBuildSpots != nullptr) {
        delete[] allowedBuildSpots;
        allowedBuildSpots = nullptr;
    }
    // Clean up tower memory to prevent leaks
    for (int i = 0; i < maxTowers; i++) {
        if (activeTowers[i] != nullptr) delete activeTowers[i];
    }
    delete[] activeTowers;

    if (testEnemy != nullptr) {
        delete testEnemy;
    }
}

void GameMechanics::loadBuildSpots() 
{
    string towerFile = "assets/TextFiles/level_" + to_string(levelNumber) + "_towers.txt";
    ifstream textFile(towerFile);
    
    if (textFile.is_open()) {
        textFile >> numBuildSpots;
        allowedBuildSpots = new Vector2f[numBuildSpots];
        for (int i = 0; i < numBuildSpots; i++) {
            textFile >> allowedBuildSpots[i].x >> allowedBuildSpots[i].y;
        }
        textFile.close();
    } else {
        numBuildSpots = 0;
        allowedBuildSpots = nullptr;
    }
}

void GameMechanics::update(float deltaTime, sf::Vector2f mousePos) 
{
    
    hud.updateGold(currentGold);

    // If the user presses Escape or Right-Clicks, drop the tower from the mouse
    if (Keyboard::isKeyPressed(Keyboard::Key::Escape) || Mouse::isButtonPressed(Mouse::Button::Right)) {
        hud.clearHolding();
        isCellSelected = false; // Turns off grid highlight
    }

   
    // Make sure all placed towers run their logic (like shooting or timers)
    for (int i = 0; i < maxTowers; i++) {
        if (activeTowers[i] != nullptr) {
            activeTowers[i]->update(deltaTime);
        }
    }

   
    // Snap mouse to the nearest 40x40 grid cell
    float snapX = floor(mousePos.x / CELL_SIZE) * CELL_SIZE;
    float snapY = floor(mousePos.y / CELL_SIZE) * CELL_SIZE;
    currentHoverPos = sf::Vector2f(snapX, snapY);
    
    
    float hoverCenterX = snapX + (CELL_SIZE / 5.0f);
    float hoverCenterY = snapY + (CELL_SIZE / 4.5f);

    // Clear grid selection if the mouse moves away from the clicked cell
    if (isCellSelected && (currentHoverPos.x != selectedCellPos.x || currentHoverPos.y != selectedCellPos.y)) {
        isCellSelected = false;
    }

    // Hide colored circle by default
    hoverRadiusCircle.setFillColor(sf::Color::Transparent);
    hoverRadiusCircle.setOutlineColor(sf::Color::Transparent);

    
    // If a cell is clicked, move the circle there and check if it is free
    if (isCellSelected) {
        float selCenterX = selectedCellPos.x + (CELL_SIZE / 2.0f);
        float selCenterY = selectedCellPos.y + (CELL_SIZE / 2.0f);
        
        hoverRadiusCircle.setPosition({selCenterX, selCenterY});

        // Use isSpotFree to check terrain AND existing towers
        if (isSpotFree(selectedCellPos.x, selectedCellPos.y)) {
            hoverRadiusCircle.setFillColor(sf::Color(0, 255, 0, 40));     // Green tint
            hoverRadiusCircle.setOutlineColor(sf::Color(0, 255, 0, 150)); // Green border
        } else {
            hoverRadiusCircle.setFillColor(sf::Color(255, 0, 0, 30));     // Red tint
            hoverRadiusCircle.setOutlineColor(sf::Color(255, 0, 0, 180)); // Red border
        }
    }

    //calculates bounded grid lines
    boundedGridLines.clear();

    if (!isCellSelected) {
        sf::Color lineColor(255, 255, 255, 120);

        float startX = floor((hoverCenterX - gridLineRadius) / CELL_SIZE) * CELL_SIZE;
        float endX   = floor((hoverCenterX + gridLineRadius) / CELL_SIZE) * CELL_SIZE;
        
        float startY = floor((hoverCenterY - gridLineRadius) / CELL_SIZE) * CELL_SIZE;
        float endY   = floor((hoverCenterY + gridLineRadius) / CELL_SIZE) * CELL_SIZE;

        for (float x = startX; x <= endX; x += CELL_SIZE) {
            float dx = x - hoverCenterX;
            if (abs(dx) <= gridLineRadius) {
                float dy = sqrt((gridLineRadius * gridLineRadius) - (dx * dx));
                boundedGridLines.append(sf::Vertex{sf::Vector2f(x, hoverCenterY - dy), lineColor});
                boundedGridLines.append(sf::Vertex{sf::Vector2f(x, hoverCenterY + dy), lineColor});
            }
        }

        for (float y = startY; y <= endY; y += CELL_SIZE) {
            float dy = y - hoverCenterY;
            if (abs(dy) <= gridLineRadius) {
                float dx = sqrt((gridLineRadius * gridLineRadius) - (dy * dy));
                boundedGridLines.append(sf::Vertex{sf::Vector2f(hoverCenterX - dx, y), lineColor});
                boundedGridLines.append(sf::Vertex{sf::Vector2f(hoverCenterX + dx, y), lineColor});
            }
        }
    }

    // Update HUD elements last 
    hud.update(mousePos);

    
    if (testEnemy != nullptr) {
        testEnemy->update(deltaTime);
        
        if (testEnemy->reachedBase()) {
            cout << "Enemy reached base!" << endl;
            delete testEnemy;
            testEnemy = nullptr;
        }
    }
}

void GameMechanics::render(sf::RenderWindow& window) 
{
    // Draw base map
    window.draw(mapSprite);
    
    // Draw colored validation circle and grid lines
    window.draw(hoverRadiusCircle);
    window.draw(boundedGridLines);
    
    //  Draw all placed physical towers 
    for (int i = 0; i < maxTowers; i++) {
        if (activeTowers[i] != nullptr) {
            activeTowers[i]->render(window);
        }
    }

    // Draw the Cards on top of everything
    hud.render(window);

    if (testEnemy != nullptr) {
        testEnemy->render(window);
    }
}

void GameMechanics::handleMouseClick(sf::Vector2f mousePos) 
{

    cout << mousePos.x << " " << mousePos.y << endl;

    //  Checks if a card was clicked FIRST
    if (hud.handleCardClick(mousePos)) {
        return; // We picked up a tower, ignore the grid completely
    }

    // Snap click to grid coordinates
    float snapX = floor(mousePos.x / CELL_SIZE) * CELL_SIZE;
    float snapY = floor(mousePos.y / CELL_SIZE) * CELL_SIZE;

    // Save the clicked location and show the colored validation circle
    selectedCellPos = sf::Vector2f(snapX, snapY);
    isCellSelected = true;

    //  Tower Placement Logic
    if (hud.holdingType != TowerType::NONE) {
        
        // Ensure the spot is valid grass AND no tower is already there
        if (isSpotFree(snapX, snapY)) {
            
            // Loop through our array to find an empty slot
            for (int i = 0; i < maxTowers; i++) {
                if (activeTowers[i] == nullptr) {
                    
                    // Shift placement to the exact center of the 40x40 cell
                    float placeX = snapX + (CELL_SIZE / 2.0f);
                    float placeY = snapY + (CELL_SIZE / 2.0f);

                    // Create the correct child class based on HUD selection
                    if (hud.holdingType == TowerType::BASIC)       activeTowers[i] = new BasicTower(placeX, placeY);
                    else if (hud.holdingType == TowerType::SNIPER) activeTowers[i] = new SniperTower(placeX, placeY);
                    else if (hud.holdingType == TowerType::CANNON) activeTowers[i] = new CannonTower(placeX, placeY);
                    else if (hud.holdingType == TowerType::MG)     activeTowers[i] = new MachineGunTower(placeX, placeY);
                    
                    //Deduct the exact cost of the tower from total
                    int cost = hud.getTowerCost(hud.holdingType);
                    modifyGold(-cost);
                    
                    std::cout << "Tower successfully placed!" << std::endl;
                    hud.clearHolding(); // Empty hand after placing
                    isCellSelected = false; // Turn off grid highlight
                    break;
                }
            }
        } else {
            std::cout << "Spot taken or invalid! Cannot build here." << std::endl;
        }
    }
}

bool GameMechanics::isSpotFree(float checkX, float checkY) const 
{
    // Fail safe check
    if (allowedBuildSpots == nullptr) return false;

    // 1. Check if the spot is valid terrain according to the text file
    bool validTerrain = false;
    for (int i = 0; i < numBuildSpots; i++) {
        if (allowedBuildSpots[i].x == checkX && allowedBuildSpots[i].y == checkY) {
            validTerrain = true;
            break;
        }
    }
    
    // If not in the text file, return false immediately
    if (!validTerrain) return false; 

    // 2. Check if a tower is already occupying this exact spot
    // We check against the center point because we spawned towers at (snapX + 20, snapY + 20)
    float placeX = checkX + (CELL_SIZE / 2.0f);
    float placeY = checkY + (CELL_SIZE / 2.0f);
    
    for (int i = 0; i < maxTowers; i++) {
        if (activeTowers[i] != nullptr) {
            if (activeTowers[i]->getPosition().x == placeX && activeTowers[i]->getPosition().y == placeY) {
                return false; // Spot is already taken by a tower!
            }
        }
    }
    
    // If it passes both checks, it is completely free
    return true;
}
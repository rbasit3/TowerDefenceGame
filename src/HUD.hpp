

#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.hpp"

using namespace sf;

class HUD {
public: // Made public so GameMechanics can easily read the holdingType
    Texture cardTex1, cardTex2, cardTex3, cardTex4;
    Sprite cardSprite1, cardSprite2, cardSprite3, cardSprite4;

     // Holding Mechanics
    TowerType holdingType;
    Texture holdTex1, holdTex2, holdTex3, holdTex4;
    Sprite holdingSprite;

    int currentGoldHUD;

    //UI bar
    Texture goldBarTex;
    Sprite goldBarSprite;
    Font uiFont;
    Text goldText;

    HUD();
    ~HUD();

    void update(Vector2f mousePos);
    void render(RenderWindow& window);
    
    // Returns true if a card was clicked so we don't accidentally click the grid behind it
    bool handleCardClick(Vector2f mousePos);
    void clearHolding();

    //function to update text string
    void updateGold(int goldAmount);

    int getTowerCost(TowerType type) const;

};
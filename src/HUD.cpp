#include "HUD.hpp"
#include <iostream>
using namespace std;

HUD::HUD()
    : cardTex1("assets/towers/card_1.png"), cardTex2("assets/towers/card_2.png"),
      cardTex3("assets/towers/card_3.png"), cardTex4("assets/towers/card_4.png"),
      cardSprite1(cardTex1), cardSprite2(cardTex2), cardSprite3(cardTex3), cardSprite4(cardTex4),
      holdTex1("assets/towers/tower_1.png"), holdTex2("assets/towers/tower_2.png"),
      holdTex3("assets/towers/tower_3.png"), holdTex4("assets/towers/tower_4.png"),
      holdingType(TowerType::NONE),
      holdingSprite(holdTex1) ,
      goldBarTex("assets/ui/gold_bar.png"),
      goldBarSprite(goldBarTex),
      uiFont("assets/fonts/Cafeteria.otf"),
      goldText(uiFont, "500", 38),
      currentGoldHUD(0)
{
    // Horizontal layout positions for bottom UI cards
    float startX = 320.0f; 
    float fixedY = 630.0f; 
    float gap = 173.0f;    

    // Add the gap to the X-axis instead of the Y-axis
    cardSprite1.setPosition({startX + gap * 2, fixedY});
    cardSprite2.setPosition({startX, fixedY});
    cardSprite3.setPosition({startX + gap, fixedY});
    cardSprite4.setPosition({startX + gap * 3, fixedY});

    cardSprite1.setOrigin({32.0f, 42.0f});
    cardSprite2.setOrigin({32.0f, 42.0f});
    cardSprite3.setOrigin({32.0f, 42.0f});
    cardSprite4.setOrigin({32.0f, 42.0f});

    
    //gold bar logic
    
    // Position at top right of the 1280x720 screen
    goldBarSprite.setPosition({40.0f, 20.0f}); 
    
   
    goldText.setCharacterSize(38); // Nice big chunky text
    goldText.setFillColor(Color::White);
    
    // Position the text to sit perfectly inside the black area of the bar
    // You may need to tweak the X/Y slightly depending on your exact image size
    goldText.setPosition({145.0f, 27.5f});
}

HUD::~HUD() {}

int HUD::getTowerCost(TowerType type) const {
    switch (type) {
        case TowerType::BASIC:  return 35;
        case TowerType::SNIPER: return 40;
        case TowerType::CANNON: return 50;
        case TowerType::MG:     return 55;
        default:                return 0;
    }
}



void HUD::update(Vector2f mousePos) 
{
    Sprite* cards[4] = { &cardSprite1, &cardSprite2, &cardSprite3, &cardSprite4 };
    
    TowerType types[4] = { TowerType::BASIC, TowerType::SNIPER, TowerType::CANNON, TowerType::MG };
    
    for (int i = 0; i < 4; i++) {
        int cost = getTowerCost(types[i]);

        // If affordable -> original bright color; if unaffordable -> dark grey tint
        if (currentGoldHUD >= cost) {
            cards[i]->setColor(Color(255, 255, 255, 255)); // Full brightness (unlocked)
        } else {
            cards[i]->setColor(Color(90, 90, 90, 220));    // Greyed out (locked)
        }

        // Hover scale effect
        if (cards[i]->getGlobalBounds().contains(mousePos)) {
            cards[i]->setScale({1.05f, 1.05f}); 
        } else {
            cards[i]->setScale({1.0f, 1.0f});   
        }
    }

    if (holdingType != TowerType::NONE) {
        holdingSprite.setPosition(mousePos);
    }

   

}

 // ---  Actually updates the text string to match the integer ---
void HUD::updateGold(int goldAmount) 
{
    currentGoldHUD = goldAmount;
    goldText.setString(to_string(goldAmount));
}

void HUD::render(RenderWindow& window) 
{
    window.draw(cardSprite1);
    window.draw(cardSprite2);
    window.draw(cardSprite3);
    window.draw(cardSprite4);

    // Draw Gold UI elements
    window.draw(goldBarSprite);
    window.draw(goldText);

    if (holdingType != TowerType::NONE) {
        window.draw(holdingSprite);
    }
}

bool HUD::handleCardClick(Vector2f mousePos) 
{
    if (cardSprite1.getGlobalBounds().contains(mousePos) && currentGoldHUD >= getTowerCost(TowerType::BASIC)) {
        holdingType = TowerType::BASIC;
        holdingSprite.setTexture(holdTex1);
        holdingSprite.setOrigin({32.0f,40.0f}); 
        return true;
    }
    if (cardSprite2.getGlobalBounds().contains(mousePos) && currentGoldHUD >= getTowerCost(TowerType::SNIPER)) {
        holdingType = TowerType::SNIPER;
        holdingSprite.setTexture(holdTex2);
        holdingSprite.setOrigin({32.0f,40.0f});
        return true;
    }
    if (cardSprite3.getGlobalBounds().contains(mousePos) && currentGoldHUD >= getTowerCost(TowerType::CANNON)) {
        holdingType = TowerType::CANNON;
        holdingSprite.setTexture(holdTex3);
        holdingSprite.setOrigin({32.0f,40.0f});
        return true;
    }
    if (cardSprite4.getGlobalBounds().contains(mousePos) && currentGoldHUD >= getTowerCost(TowerType::MG)) {
        holdingType = TowerType::MG;
        holdingSprite.setTexture(holdTex4);
        holdingSprite.setOrigin({32.0f,40.0f});
        return true;
    }
    return false;
}

void HUD::clearHolding() {
    holdingType = TowerType::NONE;
}
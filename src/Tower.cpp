#include "Tower.hpp"

// PARENT TOWER IMPLEMENTATION
Tower::Tower(float x, float y, const string& imgPath, TowerType t) 
    : Entity(x, y, imgPath), type(t) 
{
    range = 100.0f;
    damage = 10;
}

void Tower::update(float deltaTime) {
    // Attack logic goes here later
}

void Tower::render(RenderWindow& window) {
    window.draw(sprite);
}

// CHILD TOWER IMPLEMENTATIONS
BasicTower::BasicTower(float x, float y) 
    : Tower(x, y, "assets/towers/tower_1.png", TowerType::BASIC) {}

SniperTower::SniperTower(float x, float y) 
    : Tower(x, y, "assets/towers/tower_2.png", TowerType::SNIPER) {}

CannonTower::CannonTower(float x, float y) 
    : Tower(x, y, "assets/towers/tower_3.png", TowerType::CANNON) {}

MachineGunTower::MachineGunTower(float x, float y) 
    : Tower(x, y, "assets/towers/tower_4.png", TowerType::MG) {}
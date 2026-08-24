#pragma once
#include "Entity.hpp"

enum class TowerType { NONE = 0, BASIC, SNIPER, CANNON, MG };

// PARENT CLASS
class Tower : public Entity {
protected:
    TowerType type;
    float range;
    int damage;

public:
    Tower(float x, float y, const string& imgPath, TowerType t);
    virtual ~Tower() = default;

    void update(float deltaTime) override;
    void render(RenderWindow& window) override;
};

// CHILD CLASSES
class BasicTower : public Tower {
public: BasicTower(float x, float y);
};

class SniperTower : public Tower {
public: SniperTower(float x, float y);
};

class CannonTower : public Tower {
public: CannonTower(float x, float y);
};

class MachineGunTower : public Tower {
public: MachineGunTower(float x, float y);
};
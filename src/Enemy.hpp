#pragma once
#include "Entity.hpp"
#include <string>
#include <iostream>

using namespace std;


enum class EnemyType { ENEMY_1, ENEMY_2, ENEMY_3, ENEMY_4, ENEMY_5,ENEMY_6};


class Enemy : public Entity {
protected:
    sf::Texture frames[6]; // Max 6 frames supported
    int numFrames;         // Actual number of frames this specific enemy uses
    int currentFrameIndex; 
    float frameTime;       
    float currentFrameTime;

    EnemyType type;
    
    // Future attributes placeholder
    int health;
    float moveSpeed;
    int goldReward;

    // Enemy path variables
    sf::Vector2f* pathPoints;
    int numWaypoints;
    int currentWaypoint;

public:
    // Common Constructor updated to accept the path arrays
    Enemy(float x, float y, const std::string& folderPath, int frameCount, float animSpeed, EnemyType t, sf::Vector2f* path, int pathLength);
    virtual ~Enemy() = default;

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    bool reachedBase() const;
};



class Enemy1 : public Enemy {
public: 
    Enemy1(float x, float y, sf::Vector2f* path, int pathLength);
};

class Enemy2 : public Enemy {
public: 
    Enemy2(float x, float y, sf::Vector2f* path, int pathLength);
};

class Enemy3 : public Enemy {
public: 
    Enemy3(float x, float y, sf::Vector2f* path, int pathLength);
};

class Enemy4 : public Enemy {
public: 
    Enemy4(float x, float y, sf::Vector2f* path, int pathLength);
};

class Enemy5 : public Enemy {
public: 
    Enemy5(float x, float y, sf::Vector2f* path, int pathLength);
};
class Enemy6 : public Enemy {
public: 
    Enemy6(float x, float y, sf::Vector2f* path, int pathLength);
};
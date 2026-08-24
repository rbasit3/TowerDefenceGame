#include "Enemy.hpp"
#include <iostream>

using namespace std;
using namespace sf;


Enemy::Enemy(float x, float y, const string& folderPath, int frameCount, float animSpeed, EnemyType t, Vector2f* path, int pathLength)
    : Entity(x, y, folderPath + "/frame_1.png"), // Dynamically pass first frame to Entity
      numFrames(frameCount),
      currentFrameIndex(0), 
      frameTime(animSpeed),       
      currentFrameTime(0.0f),
      type(t),
      pathPoints(path),          
      numWaypoints(pathLength),  
      currentWaypoint(1)        
{
    // Default future attributes
    health = 100;
    moveSpeed = 50.0f;
    goldReward = 10;

    // Load only the number of frames this specific enemy actually has
    for (int i = 0; i < numFrames; i++) {
        string path = folderPath + "/frame_" + to_string(i + 1) + ".png";
        if (!frames[i].loadFromFile(path)) {
            cout << "Error loading enemy frame: " << path << endl;
        }
    }
    
    sprite.setTexture(frames[0]);
    sprite.setOrigin({frames[0].getSize().x / 2.0f, frames[0].getSize().y / 2.0f});
}

void Enemy::update(float deltaTime) {
    currentFrameTime += deltaTime;
    
    if (currentFrameTime >= frameTime) {
        currentFrameTime = 0.0f; 
        
        // Loop back to 0 based on the actual number of frames (e.g. % 4 or % 6)
        currentFrameIndex = (currentFrameIndex + 1) % numFrames; 
        
        sprite.setTexture(frames[currentFrameIndex]);
    }

    // MOVEMENT LOGIC
    if (currentWaypoint < numWaypoints && pathPoints != nullptr) {
        Vector2f targetPos = pathPoints[currentWaypoint];
        float dx = targetPos.x - position.x;
        float dy = targetPos.y - position.y;
        float distance = std::sqrt((dx * dx) + (dy * dy));

        float currentSpeed = moveSpeed * deltaTime; 

        if (distance <= currentSpeed) {
            position = targetPos;
            currentWaypoint++;
        }
        else {
            
            sprite.move(Vector2f((dx / distance) * currentSpeed, (dy / distance) * currentSpeed));
            position = sprite.getPosition();
        }
    }

sprite.setPosition(position);

}

//helper function:
bool Enemy::reachedBase() const {
    return currentWaypoint >= numWaypoints;
}

void Enemy::render(RenderWindow& window) {
    window.draw(sprite);
}



Enemy1::Enemy1(float x, float y, Vector2f* path, int pathLength) 
    : Enemy(x, y, "assets/enemy/enemy_1", 4, 0.15f, EnemyType::ENEMY_1, path, pathLength) 
{
    
}

Enemy2::Enemy2(float x, float y, Vector2f* path, int pathLength) 
    : Enemy(x, y, "assets/enemy/enemy_2", 4, 0.20f, EnemyType::ENEMY_2, path, pathLength) 
{

}


Enemy3::Enemy3(float x, float y, Vector2f* path, int pathLength) 
    : Enemy(x, y, "assets/enemy/enemy_3", 3, 0.25f, EnemyType::ENEMY_3, path, pathLength) 
{

}


Enemy4::Enemy4(float x, float y, Vector2f* path, int pathLength) 
    : Enemy(x, y, "assets/enemy/enemy_4", 6, 0.25f, EnemyType::ENEMY_4, path, pathLength) 
{
    
}
Enemy5::Enemy5(float x, float y, Vector2f* path, int pathLength) 
    : Enemy(x, y, "assets/enemy/enemy_5", 6, 0.25f, EnemyType::ENEMY_5, path, pathLength) 
{
   
}
Enemy6::Enemy6(float x, float y, Vector2f* path, int pathLength) 
    : Enemy(x, y, "assets/enemy/enemy_6", 6, 0.25f, EnemyType::ENEMY_6, path, pathLength) 
{
    
}
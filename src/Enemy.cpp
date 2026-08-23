#include "Enemy.hpp"

Enemy::Enemy(float x, float y,float maxHealth,float speed,int damage,int reward): Entity(x, y), maxHealth(maxHealth), health(maxHealth), speed(speed), damage(damage), reward(reward) {}
    //not sure if i wanna override this rn or in inherited classes. daikhtai hain.
void Enemy::takeDamage(float amount)
{
    if (amount <= 0.f || !getActive())
    {
        return;
    }

    health -= amount;

    if (health <= 0.f)
    {
        health = 0.f;
        setActive(false);
    }
}
    bool Enemy:: isDead() const
    {
        if (health <= 0) {
            return true;
        }
        return false;
    }

    float Enemy:: getHealth() const
    {
        return health;
    }
    void Enemy:: setHealth(float health){
        this->health = health;
    }

    float Enemy:: getMaxHealth() const
    {
        return maxHealth;
    }
    void Enemy:: setMaxHealth(float maxHealth){
        this->maxHealth = maxHealth;
    }

    float Enemy:: getSpeed() const
    {
        return speed;
    }
    void Enemy:: setSpeed(float speed){
        this->speed = speed;
    }

    int Enemy:: getDamage() const
    {
        return damage;
    }
    void Enemy:: setDamage(int damage){
        this->damage = damage;
    }

    int Enemy:: getReward() const
    {
        return reward;
    }
    void Enemy:: setReward(int reward){
        this->reward = reward;
    }
    Enemy::~Enemy() = default;
#pragma once

#include "Entity.hpp"

class Enemy : public Entity
{
protected:
    float health;
    float maxHealth;
    float speed;
    int damage;
    int reward;

public:
    Enemy(float x, float y,
          float maxHealth,
          float speed,
          int damage,
          int reward);

    virtual ~Enemy();

    virtual void Move(float deltaTime) override = 0;
    virtual void render(sf::RenderWindow& window) override = 0;
    virtual void attack() override = 0;
    virtual void takeDamage(float amount) override = 0;

    bool isDead() const;

    float getHealth() const;
    void setHealth(float health);

    float getMaxHealth() const;
    void setMaxHealth(float maxHealth);

    float getSpeed() const;
    void setSpeed(float speed);

    int getDamage() const;
    void setDamage(int damage);

    int getReward() const;
    void setReward(int reward);
};
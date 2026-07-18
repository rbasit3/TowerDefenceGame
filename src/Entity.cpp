#include "Entity.hpp"

Entity::Entity(float x, float y)
    : position(x, y), active(true) {}

sf::Vector2f Entity::getPosition() const {
    return position;
}

void Entity::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

bool Entity::getActive() const {
    return active;
}

void Entity::setActive(bool active) {
    this->active = active;
}

Entity::~Entity() = default;

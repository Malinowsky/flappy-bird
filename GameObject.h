#pragma once
#include <SFML/Graphics.hpp>

class GameObject { 
public:
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual void Update(float deltaTime) {}
};

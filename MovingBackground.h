#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingBackground : public GameObject {
private:
    sf::Texture texture;
    float speed = 250.0f; // prêdkoœæ poruszania siê t³a

public:
    sf::Sprite sprite;
    sf::Sprite sprite2;
    MovingBackground(const std::string& filePath, float speed);
    void Draw(sf::RenderWindow& window) override;
    void Update(float deltaTime) override;
};
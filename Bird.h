#pragma once
#include "GameObject.h"
class Bird : public GameObject {
private:
    sf::Texture texture;
    sf::Sprite spriteBird;
    sf::Vector2f position;
    float dy;
    float deltaTime;
    bool movementEnabled;

public:
    Bird();
    sf::Vector2f GetPosition() const;
    float GetWidth() const;
    float GetHeight() const;
    void Draw(sf::RenderWindow& window) override;
    void Move(float dx, float dy);
    float GetMovement() const;
    void Update(float deltaTime) override;
    void Jump();
    float GetX() const;
    bool IsMovementEnabled() const;
    void SetMovementEnabled(bool enabled);
};


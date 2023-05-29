#pragma once
#include "GameObject.h"
#include <stdexcept>
#include <iostream> 
#include "Bird.h"

class Column : public GameObject {
private:
    sf::Texture texture;
    sf::Sprite spriteColumn;
    float dx; // Prêdkoœæ przesuniêcia kolumny
    float speed; // Prêdkoœæ poruszania siê kolumny
    float gapSize; // Wielkoœæ luki miêdzy kolumnami
    bool pairPassed;
    bool passed;
    bool isUpper;

public:
    Column(float x, float y, float width, float height, float speed, float gapSize, bool isUpper);
    float GetWidth() const;
    sf::Vector2f GetPosition() const;
    void Draw(sf::RenderWindow& window) override;
    void Move(float dx, float dy);
    void Update(float deltaTime) override;
    bool CollidesWith(const Column& otherColumn) const;
    bool CheckCollision(const Bird& bird) const;
    bool IsPassed() const;
    void SetPassed(bool value);
    bool IsUpper() const;
    bool PairPassed() const;
    void SetPairPassed(bool value);
};
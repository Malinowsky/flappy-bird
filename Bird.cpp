#include "Bird.h"
#include "GameObject.h"
#include <stdexcept>

Bird::Bird() : dy(0) {
    if (!texture.loadFromFile("birdv4.png"))
        throw std::runtime_error("Could not load bird image");

    spriteBird.setTexture(texture);
    spriteBird.setPosition(1366 / 2, 768 / 2);

    position = sf::Vector2f(0.0f, 0.0f);

    static sf::Clock clock; // zegar do mierzenia czasu miêdzy wywo³aniami Update
    deltaTime = clock.restart().asSeconds();
}

sf::Vector2f Bird::GetPosition() const {
    return spriteBird.getPosition();
}

float Bird::GetWidth() const {
    return spriteBird.getGlobalBounds().width;
}

float Bird::GetHeight() const {
    return spriteBird.getGlobalBounds().height;
}

void Bird::Draw(sf::RenderWindow& window) {
    window.draw(spriteBird);
}

void Bird::Move(float dx, float dy) {
    spriteBird.move(dx, dy);
    position = spriteBird.getPosition();  // dodaj tê liniê
}

float Bird::GetMovement() const{
    return dy;
}

void Bird::Update(float deltaTime) {

    dy += (9.8f * deltaTime)/150; // dodaj grawitacjê do dy (9.8 to przybli¿ona wartoœæ przyspieszenia grawitacyjnego)

    Move(0, dy);
}

void Bird::Jump() {
    dy = -5.0f/150; // negatywna prêdkoœæ pocz¹tkowa skoku
}

float Bird::GetX() const {
    return position.x;
}

bool Bird::IsMovementEnabled() const {
    return movementEnabled;
}

void Bird::SetMovementEnabled(bool enabled) {
    movementEnabled = enabled;
}



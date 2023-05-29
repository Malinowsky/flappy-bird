#include "MovingBackground.h"

MovingBackground::MovingBackground(const std::string& filePath, float speed)
    : speed(speed) {
    if (!texture.loadFromFile(filePath))
        throw std::runtime_error("Could not load background image");

    sprite.setTexture(texture);
    sprite2.setTexture(texture);


    // Ustaw poczπtkowe pozycje sprite'Ûw
    sprite.setPosition(0, 0);
    sprite2.setPosition(sprite.getGlobalBounds().width, 0);

}

void MovingBackground::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(sprite2);

}

void MovingBackground::Update(float deltaTime) {
    float movement = speed * deltaTime;

    sprite.move(-movement, 0);
    sprite2.move(-movement, 0);


    // Sprawdü, czy sprite'y opuúci≥y ekran
    if (sprite.getPosition().x + sprite.getGlobalBounds().width < 0) {
        sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);
    }
    if (sprite2.getPosition().x + sprite2.getGlobalBounds().width < 0) {
        sprite2.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, 0);
    }

}
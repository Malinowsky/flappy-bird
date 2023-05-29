#include "Player.h"

Player::Player(Bird& bird) : bird(bird) {
    isGameStarted = false;
}

void Player::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        bird.Jump();
        bird.SetMovementEnabled(true);
    }
}

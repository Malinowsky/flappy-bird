#include "Column.h"

Column::Column(float x, float y, float width, float height, float speed, float gapSize, bool isUpper)
    : dx(-speed), speed(speed), gapSize(gapSize), isUpper(isUpper), pairPassed(false) {
    if (!texture.loadFromFile("columnv2.png"))
        throw std::runtime_error("Could not load column image");

    spriteColumn.setTexture(texture);
    spriteColumn.setPosition(x, y);
    spriteColumn.setScale(width / texture.getSize().x, height / texture.getSize().y);
}

float Column::GetWidth() const {
    return spriteColumn.getGlobalBounds().width;
}

sf::Vector2f Column::GetPosition() const {
    return spriteColumn.getPosition();
}

void Column::Draw(sf::RenderWindow& window) {
    window.draw(spriteColumn);
}

void Column::Move(float dx, float dy) {
    spriteColumn.move(dx, dy);
}

void Column::Update(float deltaTime) {
    float movement = speed * deltaTime;
    Move(-movement, 0);

    // Sprawdü, czy kolumna opuúci≥a ekran
    if (spriteColumn.getPosition().x + spriteColumn.getGlobalBounds().width < 0) {
        // Ustaw nowπ pozycjÍ kolumny na prawym kraÒcu ekranu
        float screenWidth = 1366;
        float columnWidth = spriteColumn.getGlobalBounds().width;
        float newX = screenWidth + columnWidth;
        float newY = spriteColumn.getPosition().y;
        spriteColumn.setPosition(newX, newY);
    }
}

bool Column::CollidesWith(const Column& otherColumn) const {
    return spriteColumn.getGlobalBounds().intersects(otherColumn.spriteColumn.getGlobalBounds());
}

bool Column::CheckCollision(const Bird& bird) const {
    // Pobierz pozycjÍ ptaka
    sf::Vector2f birdPos = bird.GetPosition();
    float birdWidth = bird.GetWidth();
    float birdHeight = bird.GetHeight();

    // Pobierz pozycjÍ i rozmiary kolumny
    sf::Vector2f columnPos = spriteColumn.getPosition();
    float columnWidth = spriteColumn.getGlobalBounds().width;
    float columnHeight = spriteColumn.getGlobalBounds().height;

    // Sprawdü kolizjÍ wzd≥uø osi X
    bool xCollision = birdPos.x + birdWidth > columnPos.x &&
        birdPos.x < columnPos.x + columnWidth;

    // Sprawdü kolizjÍ wzd≥uø osi Y
    bool yCollision = birdPos.y + birdHeight > columnPos.y &&
        birdPos.y < columnPos.y + columnHeight;

    // ZwrÛÊ true, jeúli wystÍpuje kolizja, w przeciwnym razie false
    return xCollision && yCollision;
}

bool Column::IsPassed() const {
    return passed;
}

void Column::SetPassed(bool value) {
    passed = value;
}

bool Column::IsUpper() const {
    return isUpper;
}

bool Column::PairPassed() const {
    return pairPassed;
}

void Column::SetPairPassed(bool value) {
    pairPassed = value;
}

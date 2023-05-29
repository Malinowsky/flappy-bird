#include "Menu.h"

Menu::Menu() : countdownTime(5) {
    // Inicjalizacja t³a
    if (!backgroundTexture.loadFromFile("backgroundv2.png")) {
        throw std::runtime_error("Could not load background image");
    }
    background.setTexture(backgroundTexture);

    // Inicjalizacja przycisków
    int buttonWidth = 200;
    int buttonHeight = 50;
    int windowWidth = 1366;
    int windowHeight = 768;

    playButton.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    playButton.setPosition((windowWidth - buttonWidth) / 2, (windowHeight - buttonHeight) / 2 - buttonHeight);
    playButton.setFillColor(sf::Color::Green);

    historyButton.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    historyButton.setPosition((windowWidth - buttonWidth) / 2, (windowHeight - buttonHeight) / 2 + buttonHeight);
    historyButton.setFillColor(sf::Color::Blue);

    // Inicjalizacja fontu
    if (!font.loadFromFile("font.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    // Inicjalizacja tekstu na przyciskach
    playButtonText.setFont(font);
    playButtonText.setString("PLAY");
    playButtonText.setCharacterSize(30);
    playButtonText.setFillColor(sf::Color::White);
    playButtonText.setPosition(playButton.getPosition().x + (buttonWidth - playButtonText.getGlobalBounds().width) / 2,
        playButton.getPosition().y + (buttonHeight - playButtonText.getGlobalBounds().height) / 2);

    historyButtonText.setFont(font);
    historyButtonText.setString("RANKING");
    historyButtonText.setCharacterSize(30);
    historyButtonText.setFillColor(sf::Color::White);
    historyButtonText.setPosition(historyButton.getPosition().x + (buttonWidth - historyButtonText.getGlobalBounds().width) / 2,
        historyButton.getPosition().y + (buttonHeight - historyButtonText.getGlobalBounds().height) / 2);

    // Inicjalizacja tekstu odliczania
    countdownText.setFont(font);
    countdownText.setCharacterSize(50);
    countdownText.setFillColor(sf::Color::White);
    countdownText.setPosition(650, 350);
}

void Menu::draw(sf::RenderWindow& window) {
    // Rysowanie t³a
    window.draw(background);

    // Rysowanie przycisków
    window.draw(playButton);
    window.draw(historyButton);

    // Rysowanie tekstu na przyciskach
    window.draw(playButtonText);
    window.draw(historyButtonText);

    // Rysowanie tekstu odliczania
    window.draw(countdownText);
}

bool Menu::isPlayButtonClicked(sf::Vector2f mousePos) {
    return playButton.getGlobalBounds().contains(mousePos);
}

bool Menu::isHistoryButtonClicked(sf::Vector2f mousePos) {
    return historyButton.getGlobalBounds().contains(mousePos);
}

bool Menu::startCountdown() {
    int remainingTime = countdownTime - countdownClock.getElapsedTime().asSeconds();

    if (remainingTime <= 0) {
        return true; // Odliczanie dobieg³o koñca
    }

    // Aktualizacja tekstu odliczania
    countdownText.setString(std::to_string(remainingTime));

    return false;
}
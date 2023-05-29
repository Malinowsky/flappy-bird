#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();

    void draw(sf::RenderWindow& window);
    bool isPlayButtonClicked(sf::Vector2f mousePos);
    bool isHistoryButtonClicked(sf::Vector2f mousePos);
    bool startCountdown();

private:
    sf::Texture backgroundTexture;
    sf::Sprite background;

    sf::RectangleShape playButton;
    sf::RectangleShape historyButton;

    sf::Font font;
    sf::Text playButtonText;
    sf::Text historyButtonText;

    sf::Font countdownFont;
    sf::Text countdownText;
    sf::Clock countdownClock;
    int countdownTime;
};

#endif

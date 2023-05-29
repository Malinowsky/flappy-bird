#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Bird.h"

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Bird.h"
#include "Menu.h" // Do³¹cz nag³ówek Menu

int main() {
    try {
        sf::RenderWindow window(sf::VideoMode(1366, 728), "Flappy Bird");
        Menu menu;

        // Pêtla menu
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (menu.isPlayButtonClicked(mousePos)) {
                        Game game;
                        game.Run();
                    }
                   
                }
            }

            window.clear();
            menu.draw(window);
            window.display();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

#include "Game.h"
#include <random>



Game::Game() : window(sf::VideoMode(1366, 768), "Flappy Bird") {
    if (!backgroundTexture.loadFromFile("backgroundv2.png"))
        throw std::runtime_error("Could not load background image");

    MovingBackground* background = new MovingBackground("backgroundv2.png", 50.0f);
    AddGameObject(background);

    bird = new Bird(); // Utwórz nowy obiekt Bird
    AddGameObject(bird); // Dodaj go do listy obiektów gry

    furthestColumnX = window.getSize().x;

    // Pre-generuj kolumny
    GenerateColumns();

    if (!font.loadFromFile("font.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    flightTimeText.setCharacterSize(30);
    flightTimeText.setFillColor(sf::Color::White);
    flightTimeText.setPosition(10.f, 10.f);
    flightTimeText.setFont(font);

}

Game::~Game() {
    for (GameObject* obj : gameObjects) {
        delete obj;
    }
}

void Game::AddGameObject(GameObject* obj) {
    gameObjects.push_back(obj);
}

void Game::GenerateColumns() {
    float columnSpeed = 100.0f;
    int numPairs = 5; // Liczba par kolumn do wygenerowania

    // Oblicz szerokoœæ kolumny na podstawie dostêpnej przestrzeni
    float columnWidth = 100.0f;
    float columnGapSize = 200.0f;

    // Oblicz przesuniêcie miêdzy kolejnymi kolumnami
    float columnOffset = (window.getSize().x + columnWidth) / numPairs;

    // Generuj kolejne pary kolumn
    for (int i = 0; i < numPairs; i++) {
        // Oblicz pozycjê X dla pary kolumn
        float pairX = window.getSize().x + i * columnOffset;

        // Losuj wysokoœæ kolumny i po³o¿enie dziury
        float minHeight = 100.0f;
        float maxHeight = window.getSize().y - columnGapSize - minHeight;
        float columnHeight1 = minHeight + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxHeight - minHeight)));
        float columnHeight2 = window.getSize().y - columnHeight1 - columnGapSize;

        // Twórz obiekty kolumny i dodawaj je do gry
        Column* column1 = new Column(pairX, 0, columnWidth, columnHeight1, columnSpeed, columnGapSize, true);
        Column* column2 = new Column(pairX, columnHeight1 + columnGapSize, columnWidth, columnHeight2, columnSpeed, columnGapSize, false);

        AddGameObject(static_cast<GameObject*>(column1));
        AddGameObject(static_cast<GameObject*>(column2));
    }
}

void Game::CheckCollision() {
    for (GameObject* obj : gameObjects) {
        Column* column = dynamic_cast<Column*>(obj);
        if (column && column->CheckCollision(*bird)) {
            // Wykryto kolizjê z kolumn¹, wyœwietl napis "GAME OVER" i liczbê przekroczonych kolumn
            sf::Text gameOverText;
            sf::Font font;
            if (!font.loadFromFile("font.ttf")) {
                throw std::runtime_error("Could not load font");
            }
            gameOverText.setFont(font);
            gameOverText.setCharacterSize(50);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setString(std::string("GAME OVER - TIME : ").append(flightTimeText.getString()));
            gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
                window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2);
            window.draw(gameOverText);

            // Zatrzymaj grê
            window.display();
            sf::sleep(sf::seconds(5)); // Zatrzymaj na 2 sekundy
            window.close();
        }
    }
}


void Game::Run() {
    Player player(*bird);
    gameClock.restart();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        player.HandleInput();

        // Aktualizuj wszystkie obiekty gry
        float deltaTime = clock.restart().asSeconds();
        for (GameObject* obj : gameObjects) {
            obj->Update(deltaTime);
        }

        // SprawdŸ kolizjê miêdzy ptakiem a kolumnami
        CheckCollision();

        // Rysuj wszystkie obiekty gry
        for (GameObject* obj : gameObjects) {
            obj->Draw(window);
        }

        // Aktualizuj i wyœwietlaj czas lotu zamiast wyniku
        sf::Time flightTime = gameClock.getElapsedTime();
        std::ostringstream flightTimeStream;
        flightTimeStream << std::fixed << std::setprecision(3) << flightTime.asSeconds();
        std::string flightTimeStr = flightTimeStream.str();
        flightTimeText.setString("Flight Time: " + flightTimeStr);
        window.draw(flightTimeText);

        // SprawdŸ, czy potrzebne jest pre-generowanie kolumn
        if (gameObjects.size() <= 2) {
            GenerateColumns();
        }

        window.display();
    }
}
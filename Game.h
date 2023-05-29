#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Bird.h"
#include "Player.h"
#include "MovingBackground.h"
#include "Column.h"
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "Menu.h"

class Game 
{
private:
    std::vector<GameObject*> gameObjects;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Clock clock;
    float furthestColumnX;
    sf::Clock columnClock;

    Bird* bird;
    bool isGameStarted;
    sf::Text flightTimeText;
    sf::Clock gameClock;
    sf::Font font;


public:
    Game();
    ~Game();
    void AddGameObject(GameObject* obj);
    void Run();
    void GenerateColumns();
    void CheckCollision();
};


#pragma once
#include "Bird.h"
class Player {
private:
    Bird& bird; // Referencja do obiektu Bird, który sterujemy
    bool isGameStarted = false;

public:
    Player(Bird& bird);
    void HandleInput();
};

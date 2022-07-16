#include "Game.h"
#include "Settings.h"
// #include <iostream>
// std::cout<< <<std::endl;

int main()
{
    Game game(settings::screenW, settings::screenH, settings::fps, "Raylib Game");

    while(!game.GameShouldClose())
    {
        game.Tick();
    }

    return 0;
}
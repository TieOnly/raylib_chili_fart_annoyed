#include <assert.h>
#include "Game.h"
#include "raylib.h"

Game::Game(int width, int height, int fps, std::string title)
{
    assert(!GetWindowHandle());
    InitWindow(width, height, title.c_str());
    SetTargetFPS(fps);
}
Game::~Game() noexcept
{
    assert(GetWindowHandle());
    CloseWindow();
}
bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}
void Game::Tick() 
{
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}
void Game::Update()
{

}
void Game::Draw()
{
    ClearBackground(BLACK);
}

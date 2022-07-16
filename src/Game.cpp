#include <assert.h>
#include "Game.h"
#include "raylib.h"

Game::Game(int width, int height, int fps, std::string title)
    :
    ball( Vec2(100.0f, 100.0f), Vec2(1.0f * 60.0f, 1.0f * 60.0f) ), 
    wall( RectF{0, 0, (float)settings::screenW, (float)settings::screenH} )
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
    const float dTime = ft.Mark();

    ball.Update( dTime );
    ball.DoWallCollison( wall );
}
void Game::Draw()
{
    ClearBackground(BLACK);
    ball.Draw();
}

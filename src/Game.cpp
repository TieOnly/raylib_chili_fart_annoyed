#include <assert.h>
#include "Game.h"
#include "raylib.h"
#include <iostream>


Game::Game(int width, int height, int fps, std::string title)
    :
    ball( Vec2(100.0f, 100.0f), Vec2(10.0f * 60.0f, 10.0f * 60.0f) ), 
    wall( RectF{0, 0, (float)settings::screenW, (float)settings::screenH} ),
    paddle( Vec2{380.0f, 400.0f}, WHITE )
{
    assert(!GetWindowHandle());
    InitWindow(width, height, title.c_str());
    SetTargetFPS(fps);

    int i = 0;
    // const Vec2 topleft{0.0f, 0.0f};
    for(int y = 0; y < nBrickY; ++y)
    {
        for(int x = 0; x < nBrickX; ++x)
        {
            bricks[i] = Brick(
                Vec2{float(x * brickWidth + brickWidth / 2), float(y * brickHeight + brickHeight / 2)},
                colorBricks[y]
            );
            i++;
        }
    }
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
    
    for(int k = nBrickY * nBrickX - 1; k >= 0; --k)
    {
        if(bricks[k].DoBallCollision(ball))
        {
            break;
        }
    }

    paddle.Update( dTime );
    paddle.DoBallCollision( ball );
    paddle.DoWallCollision( wall );

}
void Game::Draw()
{
    ClearBackground(BLACK);
    ball.Draw();
    // for( const Brick& b : bricks)
    // {
    //     b.Draw();
    // }
    for(int k = nBrickY * nBrickX - 1; k >= 0; --k)
    {
        bricks[k].Draw();
    }
    paddle.Draw();
}

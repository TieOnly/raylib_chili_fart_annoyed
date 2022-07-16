#pragma once
#include <string>
#include "Settings.h"
#include "raylib.h"
#include "Vec2.h"
#include "FrameTimer.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class Game
{
public:
    Game(int width, int height, int fps, std::string title);
    ~Game() noexcept;
    Game (const Game& another) = delete;
    Game& operator = (const Game& another) = delete;
    bool GameShouldClose() const;
    void Tick();
private:
    void Update();
    void Draw();

    FrameTimer ft;
    Ball ball;
    RectF wall;
    Paddle paddle;

    static constexpr int nBrickY = 4;
    static constexpr int nBrickX = 20;
    static constexpr float brickWidth = 40.0f;
    static constexpr float brickHeight = 20.0f;
    Color colorBricks[4] = {RED, GREEN, SKYBLUE, RAYWHITE};
    Brick bricks[nBrickY * nBrickX];

};

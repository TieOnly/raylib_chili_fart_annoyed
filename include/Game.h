#pragma once
#include <string>
#include "Settings.h"
#include "raylib.h"
#include "Vec2.h"
#include "FrameTimer.h"
#include "Ball.h"


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
};

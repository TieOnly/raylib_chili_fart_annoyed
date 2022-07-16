#pragma once
#include "raylib.h"
#include "RectF.h"
#include "Ball.h"


class Brick
{
public:
    Brick() = default;
    Brick(const Vec2 center_in, Color color_in);
    bool DoBallCollision(Ball& ball);
    RectF GetRectangle() const;
    void Draw() const;
private:
    Vec2 center;
    static constexpr float halfWidth = 20.0f;
    static constexpr float halfHeight = 10.0f;
    Color color;
    bool destroyed = false;
};
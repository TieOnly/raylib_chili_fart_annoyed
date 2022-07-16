#pragma once
#include "raylib.h"
#include "RectF.h"
#include "Ball.h"


class Brick
{
public:
    Brick() = default;
    Brick(const RectF& rect_in, Color color_in);
    bool DoBallCollision(Ball& ball);
    void Draw() const;
private:
    RectF rect;
    Color color;
    bool destroyed = false;
};
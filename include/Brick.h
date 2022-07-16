#pragma once
#include "raylib.h"
#include "Vec2.h"


class Brick
{
public:
    Brick(const Vec2& pos_in, const Vec2& widthHeight_in, Color color_in);
    void Draw() const;
private:
    Vec2 pos;
    Vec2 widthHeight;
    Color color;
};
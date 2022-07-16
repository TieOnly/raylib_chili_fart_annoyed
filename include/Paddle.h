#pragma once
#include "raylib.h"
#include "RectF.h"
#include "Vec2.h"
#include "Ball.h"

class Paddle
{
public:
    Paddle(const Vec2& pos_in, Color color_in);
    bool DoBallCollision(Ball& ball) const;
    void DoWallCollision(const RectF& wall);
    RectF GetRectangle() const;
    void Update( const float& dTime );
    void Draw() const;
private:
    Vec2 pos;
    static constexpr float speed = 300.0f;
    static constexpr float halfWidth = 60.0f;
    static constexpr float halfHeight = 20.0f;
    Color color;
};
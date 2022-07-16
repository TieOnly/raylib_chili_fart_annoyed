#pragma once
#include "raylib.h"
#include "Vec2.h"
#include "RectF.h"

class Ball
{
public:
    Ball(const Vec2& center_in, const Vec2& vel_in);
    void Update( const float dTime );
    void DoWallCollison( const RectF& wall);
    void ReBoundX();
    void ReBoundY();
    RectF GetRectangle();
    void Draw() const;
private:
    Vec2 center;
    Vec2 vel;
    static constexpr float radius = 6.0f;
    bool collided = false;
};
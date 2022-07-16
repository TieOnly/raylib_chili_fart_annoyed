#include "Brick.h"
#include <iostream>

Brick::Brick(const Vec2 center_in, Color color_in)
{
    center = center_in;
    color = color_in;
}
bool Brick::DoBallCollision(Ball& ball)
{
    RectF rect = GetRectangle();
    // std::cout << rect.top << ":" << rect.bottom << "," << rect.left << ":" << rect.right << std::endl;
    if(rect.IsOverLapping( ball.GetRectangle() ) && !destroyed && ball.GetVelocity().y < 0)
    {
        ball.ReBoundY();
        destroyed = true;
        return true;
    }
    return false;
}
RectF Brick::GetRectangle() const
{
    return RectF::FromCenter(center, halfWidth, halfHeight);
}
void Brick::Draw() const
{
    if(!destroyed)
    {
        RectF rect = GetRectangle();
        DrawRectangle((int)rect.left, (int)rect.top, (int)halfWidth * 2, (int)halfHeight * 2, color);
    }
}
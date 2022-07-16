#include "Brick.h"

Brick::Brick(const RectF& rect_in, Color color_in)
{
    rect = rect_in;
    color = color_in;
}
bool Brick::DoBallCollision(Ball& ball)
{
    if(rect.IsOverLapping( ball.GetRectangle() ) && !destroyed)
    {
        ball.ReBoundY();
        destroyed = true;
        return true;
    }
    return false;
}
void Brick::Draw() const
{
    if(!destroyed)
    {
        rect.DrawRectF(color);
    }
}
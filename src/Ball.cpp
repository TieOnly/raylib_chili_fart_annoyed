#include "Ball.h"

Ball::Ball(const Vec2& center_in, const Vec2& vel_in)
    :
    center( center_in ),
    vel( vel_in )
{
}
void Ball::Update( const float dTime )
{
    center += vel * dTime;
}
void Ball::DoWallCollison( const RectF& wall)
{
    RectF rect = GetRectangle();
    if(rect.left < wall.left)
    {
        center.x += wall.left - rect.left;
        ReBoundX();
        collided = true;
    } else if(rect.right > wall.right) {
        center.x -= rect.right - wall.right;
        ReBoundX();
        collided = true;
    }
    if(rect.top < wall.top)
    {
        center.y += wall.top - rect.top;
        ReBoundY();
        collided = true;
    } else if(rect.bottom > wall.bottom) {
        center.y -= rect.bottom - wall.bottom;
        ReBoundY();
        collided = true;
    }
}
Vec2 Ball::GetVelocity() const
{
    return vel;
}
RectF Ball::GetRectangle() const
{
    return RectF::FromCenter(center, radius, radius);
}
void Ball::ReBoundX()
{
    vel.x = - vel.x;
}
void Ball::ReBoundY()
{
    vel.y = - vel.y;
}
void Ball::Draw() const
{
    DrawCircle((int)center.x, (int)center.y, (int)radius, WHITE);
}
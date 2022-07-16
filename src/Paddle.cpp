#include "Paddle.h"

Paddle::Paddle(const Vec2& pos_in, Color color_in)
    :
    pos(pos_in),
    color(color_in)
{

}
bool Paddle::DoBallCollision(Ball& ball) const
{
    RectF rectBall = ball.GetRectangle();
    if(ball.GetVelocity().y > 0 && rectBall.IsOverLapping( GetRectangle() ))
    {
        ball.ReBoundY();
        return true;
    }
    return false;
}
void Paddle::DoWallCollision(const RectF& wall)
{
    const float left = pos.x - halfWidth;
    const float right = pos.x + halfWidth;
    if(left < wall.left)
    {
        pos.x += wall.left - left;
    } else if(right > wall.right) {
        pos.x -= right - wall.right;
    }
}
void Paddle::Update( const float& dTime )
{
    if(IsKeyDown(KEY_LEFT))
    {
        pos.x -= speed * dTime;
    }
    if(IsKeyDown(KEY_RIGHT))
    {
        pos.x += speed * dTime;
    }
}
RectF Paddle::GetRectangle() const
{
    return RectF::FromCenter(pos, halfWidth, halfHeight);
}
void Paddle::Draw() const
{
    RectF rect = GetRectangle();
    DrawRectangle((int)rect.left, (int)rect.top, (int)halfWidth * 2, (int)halfHeight * 2, color);
}
#include "RectF.h"

RectF::RectF(float left_in, float top_in, float right_in, float bottom_in)
    :
    left(left_in),
    top(top_in),
    right(right_in),
    bottom(bottom_in)
{

}
RectF::RectF(const Vec2& topLeft, const Vec2& bottomRight)
    :
    RectF(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{

}
RectF::RectF(const Vec2& topLeft, const float& width, const float& height)
    :
    RectF(topLeft, topLeft + Vec2{width, height})
{

}
RectF RectF::FromCenter(const Vec2& center, const float& halfWidth, const float& halfHeight)
{
    const Vec2 toAngle( halfWidth, halfHeight );
    return RectF{ center - toAngle, center + toAngle};
}
bool RectF::IsOverLapping(const RectF& other) const
{
    return right > other.left && bottom > other.top 
        && left < other.right && top < other.bottom;
}
#pragma once
#include "Vec2.h"

class RectF
{
public:
    RectF() = default;
    RectF(float left_in, float top_in, float right_in, float bottom_in);
    RectF(const Vec2& topLeft, const Vec2& bottomRight);
    RectF(const Vec2& topLeft, const float& width, const float& height);
    static RectF FromCenter(const Vec2& center, const float& halfWidth, const float& halfHeight);
    bool IsOverLapping(const RectF& other) const;
public:
    float left;
    float top;
    float right;
    float bottom;
};
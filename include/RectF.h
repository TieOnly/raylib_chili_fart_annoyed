#pragma once
#include "Vec2.h"

class RectF
{
public:
    RectF() = default;
    RectF(float left_in, float top_in, float right_in, float bottom_in);
    RectF(const Vec2& topLeft, const Vec2& bottomRight);
    RectF(const Vec2& topLeft, const float& width, const float& height);
    bool IsOverLapping(const RectF& other) const;
private:
    float left;
    float right;
    float top;
    float bottom;
};
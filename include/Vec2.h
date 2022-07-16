#pragma once
#include <cmath>

class Vec2
{
public:
    Vec2() = default;
    constexpr Vec2(float x_in, float y_in)
        :
        x(x_in),
        y(y_in)
    {

    }

    constexpr float GetX() const {return x;}
    constexpr float GetY() const {return y;}
    constexpr void SetX(float x_in) {x = x_in;}
    constexpr void SetY(float y_in) {y = y_in;}
    
public:
    float x;
    float y;

public:
    constexpr bool operator == (const Vec2& rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }
    constexpr bool operator != (const Vec2& rhs) const
    {
        return !(*this == rhs);
    }
    constexpr Vec2 operator + (const Vec2& rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }
    constexpr Vec2 operator + (const float& rhs) const
    {
        return {x + rhs, y + rhs};
    }
    constexpr Vec2& operator += (const Vec2& rhs) 
    {
        return (*this = *this + rhs);
    }
    constexpr Vec2 operator - (const Vec2& rhs) const
    {
        return {x - rhs.x, y - rhs.y};
    }
    constexpr Vec2 operator - (const float& rhs) const
    {
        return {x - rhs, y - rhs};
    }
    constexpr Vec2& operator -= (const Vec2& rhs) 
    {
        return (*this = *this - rhs);
    }
    constexpr Vec2 operator * (const Vec2& rhs) const
    {
        return {x * rhs.x, y * rhs.y};
    }
    constexpr Vec2 operator * (const float& rhs) const
    {
        return {x * rhs, y * rhs};
    }
    constexpr Vec2& operator *= (const Vec2& rhs) 
    {
        return (*this = *this * rhs);
    }
    constexpr float GetLengthSq() const
    {
        return (x * x + y * y);
    }
    constexpr float GetLength() const
    {
        return std::sqrt( GetLengthSq() );
    }
    Vec2& Nomarlize()
    {
        return *this = GetNormalize();
    }
    Vec2 GetNormalize() const
    {
        const float len = GetLength();
        if( len != 0.0f )
        {
            return *this * (1.0f / len);
        }
        return *this;
    }
};

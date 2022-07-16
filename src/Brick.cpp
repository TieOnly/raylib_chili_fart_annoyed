#include "Brick.h"

Brick::Brick(const Vec2& pos_in, const Vec2& widthHeight_in, Color color_in)
    :
    pos(pos_in),
    widthHeight(widthHeight_in),
    color(color_in)
{

}
void Brick::Draw() const
{
    DrawRectangle((int)pos.x, (int)pos.y, (int)widthHeight.x, (int)widthHeight.y, color);
}
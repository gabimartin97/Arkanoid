#include "Brick.h"





Brick::Brick(const Vec2 & topLeft_in, const float width_in, const float height_in, const Color & c_in)
	:
	rect(topLeft_in, width_in, height_in)
{
	c = c_in;
}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, c);
}

#include "RectF.h"

RectF::RectF(const Vec2 & topLeft_in, const Vec2 &bottomRight_in)
{
	topLeft = topLeft_in;
	bottomRight = bottomRight_in;
}

RectF::RectF(const Vec2 & topLeft_in, const float width, const float height)
{
	topLeft = topLeft_in;
	bottomRight = Vec2(topLeft_in.x + width, topLeft_in.y + height);
}

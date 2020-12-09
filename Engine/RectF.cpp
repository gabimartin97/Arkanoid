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

RectF RectF::FromCenter(const Vec2 & center, const float halfWidth, const float halfHeight)
{
	Vec2 topLeft = center - Vec2(halfWidth, halfHeight);
	Vec2 bottomRight = center + Vec2(halfWidth, halfHeight);
	return RectF(topLeft,bottomRight);
}

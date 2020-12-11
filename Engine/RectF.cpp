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

bool RectF::IsOverlappingWith(const RectF & rect_in) const
{
	float left = topLeft.x;
	float right = bottomRight.x;
	float top = topLeft.y;
	float bottom = bottomRight.y;
	float left_in = rect_in.topLeft.x;
	float right_in = rect_in.bottomRight.x;
	float top_in = rect_in.topLeft.y;
	float bottom_in = rect_in.bottomRight.y;
	bool overlappingX = false;
	bool overlappingY = false;

		if ((right_in >= left && right_in <= right) || (left_in >= left && left_in <= right)) {
			overlappingX = true;
		}

		if ((top_in <= bottom && top_in >= top) || (bottom_in <= bottom && bottom_in >= top)) {
			overlappingY = true;
		}

	return (overlappingX && overlappingY);
}

RectF RectF::FromCenter(const Vec2 & center, const float halfWidth, const float halfHeight)
{
	Vec2 topLeft = center - Vec2(halfWidth, halfHeight);
	Vec2 bottomRight = center + Vec2(halfWidth, halfHeight);
	return RectF(topLeft,bottomRight);
}

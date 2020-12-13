#include "RectF.h"

RectF::RectF(const Vec2 & topLeft_in, const Vec2 &bottomRight_in)
{
	topLeft = topLeft_in;
	bottomRight = bottomRight_in;
	 left = topLeft.x;
	 right = bottomRight.x;
	 top = topLeft.y;
	 bottom = bottomRight.y;

}

RectF::RectF(const Vec2 & topLeft_in, const float width, const float height)
	:
	RectF(topLeft_in, Vec2(topLeft_in.x + width, topLeft_in.y + height))
{
}

void RectF::Update(const Vec2 & topLeft_in, const Vec2 & bottomRight_in)
{
	topLeft = topLeft_in;
	bottomRight = bottomRight_in;
	left = topLeft.x;
	right = bottomRight.x;
	top = topLeft.y;
	bottom = bottomRight.y;
}

RectF RectF::FromCenter(const Vec2 & center, const float halfWidth, const float halfHeight)
{
	Vec2 topLeft = center - Vec2(halfWidth, halfHeight);
	Vec2 bottomRight = center + Vec2(halfWidth, halfHeight);
	return RectF(topLeft, bottomRight);
}

RectF RectF::GetExpanded(const float scalar) const
{
	Vec2 scaledTopLeft = Vec2(topLeft.x - scalar, topLeft.y - scalar);
	Vec2 scaledBottomRight = Vec2(bottomRight.x + scalar, bottomRight.y + scalar);
	return RectF(scaledTopLeft,scaledBottomRight);
}


bool RectF::IsOverlappingWith(const RectF & rect_in) const
{
	bool overlappingX = false;
	bool overlappingY = false;

		if ((rect_in.right >= left && rect_in.right <= right) || (rect_in.left >= left && rect_in.left <= right)) {
			overlappingX = true;
		}

		if ((rect_in.top <= bottom && rect_in.top >= top) || (rect_in.bottom <= bottom && rect_in.bottom >= top)) {
			overlappingY = true;
		}

	return (overlappingX && overlappingY);
}



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

bool Brick::DoBallCollision(Ball & ball)
{
	RectF ballHitbox = ball.GetHitbox();
	if (rect.IsOverlappingWith(ballHitbox)) {
		if (!isDestroyed) {
			isDestroyed = true;
			if (ballHitbox.top <= rect.bottom && ballHitbox.bottom >= rect.bottom) ball.ReboundY();
			else
				if (ballHitbox.bottom >= rect.top && ballHitbox.top <= rect.top) ball.ReboundY();

			if (ballHitbox.right >= rect.left && ballHitbox.left <= rect.left) ball.ReboundX();
			else
				if (ballHitbox.left <= rect.right && ballHitbox.right >= rect.right) ball.ReboundX();
			return true;
		}
}
	return false;
}

bool Brick::IsDestroyed() const
{
	return isDestroyed;
}

RectF Brick::GetExpanded(const float scalar) const
{	
	
	return RectF(rect.GetExpanded(scalar));
}

Color Brick::GetColor(void) const
{
	return c;
}



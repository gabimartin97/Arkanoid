#include "Paddle.h"

Paddle::Paddle(const Vec2 & topLeft_in, const float width_in, const float height_in, Color c_in)
	:
	body(topLeft_in, width_in, height_in)
{
	c = c_in;
	padHeight = height_in;
	padWidth = width_in;
}

void Paddle::Draw(Graphics & gfx) const
{
	gfx.DrawRect(body, c);
}

void Paddle::Update(const float dt, const unsigned char data)
{
	if (data == 'l') {
		float newTopLeftX = body.topLeft.x - lateralSpeed * dt;
		float newBottomRightX = body.bottomRight.x - lateralSpeed * dt;
		body.Update(Vec2(newTopLeftX, body.topLeft.y), Vec2(newBottomRightX, body.bottomRight.y));
	} else 
		if (data == 'r') {
			float newTopLeftX = body.topLeft.x + lateralSpeed * dt;
			float newBottomRightX = body.bottomRight.x + lateralSpeed * dt;
			body.Update(Vec2(newTopLeftX, body.topLeft.y), Vec2(newBottomRightX, body.bottomRight.y));
		}

}

void Paddle::DoWallCollision(const RectF & walls)
{
	if (body.left < walls.topLeft.x)
	{
		body.Update(Vec2(walls.topLeft.x, body.top),Vec2(walls.topLeft.x + padWidth, body.bottom));
	}
	else
		if (body.right > walls.bottomRight.x) {
			body.Update(Vec2(walls.bottomRight.x - padWidth, body.top), Vec2(walls.bottomRight.x, body.bottom));
		}
	
}

bool Paddle::DoBallCollision(Ball & ball) const
{
	RectF ballHitbox = ball.GetHitbox();
	if (body.IsOverlappingWith(ballHitbox)) {
		
		if (ballHitbox.top <= body.bottom && ballHitbox.bottom >= body.bottom) ball.ReboundY();
		else
			if (ballHitbox.bottom >= body.top && ballHitbox.top <= body.top) ball.ReboundY();

		if (ballHitbox.right >= body.left && ballHitbox.left <= body.left) ball.ReboundX();
		else
			if (ballHitbox.left <= body.right && ballHitbox.right >= body.right) ball.ReboundX();
		return true;
	}
	return false;
}

#include "Ball.h"

Ball::Ball(const Vec2 & center, const Vec2 & velocity_in)
{
	position = center;
	velocity = velocity_in;
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(position, gfx);
}

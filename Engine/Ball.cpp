#include "Ball.h"

Ball::Ball(const Vec2 & center, const Vec2 & velocity_in)
	:
	hitbox(Vec2(center.x-radius,center.y-radius),Vec2(center.x + radius, center.y + radius))
{
	position_center = center;
	velocity = velocity_in;
		
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(position_center, gfx);
}

void Ball::Update(const float dt)
{
	position_center = position_center + velocity * dt;
	hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
	
}

void Ball::DoWallCollision(const RectF & walls)
{
	if (position_center.x - radius <= walls.topLeft.x)
	{
		ReboundX();
		position_center.x = walls.topLeft.x + radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
	}
	else if (position_center.x + radius >= walls.bottomRight.x)
	{
		ReboundX();
		position_center.x = walls.bottomRight.x - radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
	}
	if (position_center.y - radius <= walls.topLeft.y)
	{
		ReboundY();
		position_center.y = walls.topLeft.y + radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
	}
	else if (position_center.y + radius >= walls.bottomRight.y)
	{
		ReboundY();
		position_center.y = walls.bottomRight.y - radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
	}
	
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

RectF Ball::GetHitbox() const
{
	return hitbox;
}

void Ball::BallHitboxDraw(Graphics& gfx) const
{
	gfx.DrawRect(hitbox, Colors::Red);
}

Vec2 Ball::ReturnCenter() const
{
	return position_center;
}

Vec2 Ball::ReturnVelocity() const
{
	return velocity;
}

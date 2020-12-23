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

bool Ball::DoWallCollision(const Wall & walls, bool* isGameOver)
{
	if (position_center.x - radius <= walls.borders.topLeft.x)
	{
		ReboundX();
		position_center.x = walls.borders.topLeft.x + radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
		return true;
	}
	else if (position_center.x + radius >= walls.borders.bottomRight.x)
	{
		ReboundX();
		position_center.x = walls.borders.bottomRight.x - radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
		return true;
	}
	else if (position_center.y - radius <= walls.borders.topLeft.y)
	{
		ReboundY();
		position_center.y = walls.borders.topLeft.y + radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
		return true;
	}
	else if (position_center.y + radius >= walls.borders.bottomRight.y)
	{
		ReboundY();
		position_center.y = walls.borders.bottomRight.y - radius;
		hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));
		*isGameOver = true;

		return true;
	}
	else
	{
		return false;
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

void Ball::ScaleVelocityVector(const Vec2 & velocity_in)
{
	velocity = Vec2((velocity_in.x * speed), (velocity_in.y * speed));
}

void Ball::IncreaseSpeed(const float step)
{
	speed += step;
}

void Ball::SetSpeed(const float speed_in)
{
	speed = speed_in;
}

void Ball::Move(const Vec2 & center_in)
{
	position_center = center_in;
	hitbox.Update(Vec2(position_center.x - radius, position_center.y - radius), Vec2(position_center.x + radius, position_center.y + radius));

}

float Ball::ReturnRadius() const
{
	return radius;
}

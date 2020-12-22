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

bool Paddle::DoBallCollision(Ball & ball) 
{
	

		RectF ballHitbox = ball.GetHitbox();
		if (body.IsOverlappingWith(ballHitbox))
		{
			if (!isCooldown)
			{

				bool verticalSuperiorCollision = false;
				bool verticalInferiorCollision = false;
				bool horizontalLeftCollision = false;
				bool horizontalRightCollision = false;
				bool betweenX = false;
				bool betweenY = false;
				Vec2 ballCenter = ball.ReturnCenter();

				betweenX = ballCenter.x >= body.left && ballCenter.x <= body.right;
				betweenY = ballCenter.y >= body.top && ballCenter.y <= body.bottom;
				/* ----------------------- COLISIONES BÁSICAS ------------------------*/
				if ((ballCenter.y < body.top && ballCenter.y < body.bottom) && betweenX)
				{
					verticalSuperiorCollision = true;
				}
				else
					if ((ballCenter.y > body.top && ballCenter.y > body.bottom) && betweenX)
					{
						verticalInferiorCollision = true;
					}

				if ((ballCenter.x < body.left && ballCenter.x < body.right) && betweenY)
				{
					horizontalLeftCollision = true;
				}
				else
					if ((ballCenter.x > body.left && ballCenter.x > body.right) && betweenY)
					{
						horizontalRightCollision = true;
					}

				if (verticalInferiorCollision || verticalSuperiorCollision) {
					ball.ReboundY();

				}
				else
					if (horizontalLeftCollision || horizontalRightCollision) {
						ball.ReboundX();

					}
					else
						/* ----------------------- COLISIONES ESQUINERAS ------------------------*/
					{
						Vec2 brickBallVector = ball.ReturnCenter() - ReturnCenter();
						if (std::signbit(ball.ReturnVelocity().x) == std::signbit(brickBallVector.x))
						{
							ball.ReboundY();

						}
						else
						{
							ball.ReboundX();

						}


					}
				isCooldown = true;
				return true;
			}
			
		}
		return false;
}

Vec2 Paddle::ReturnCenter() const
{
	float centerX = body.topLeft.x + ((body.right - body.left) / 2.0f);
	float centerY = body.topLeft.y + ((body.bottom - body.top) / 2.0f);
	return Vec2(centerX, centerY);
	
}

void Paddle::DeactivateCooldown()
{
	isCooldown = false;
}

bool Paddle::DoVectorialBallCollision(Ball & ball)
{
	RectF ballHitbox = ball.GetHitbox();
	if (body.IsOverlappingWith(ballHitbox))
	{
		if (!isCooldown)
		{
			Vec2 padBallVector = ball.ReturnCenter() - ReturnCenter();
			
				Vec2 ballVelocityScalar(padBallVector.GetNormalized());
				ball.ScaleVelocityVector(ballVelocityScalar);
			
			isCooldown = true;
			return true;
		}
		return false;
	}
	return false;
}

float Paddle::ReturnHeight() const
{
	return padHeight;
}

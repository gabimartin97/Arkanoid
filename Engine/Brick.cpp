#include "Brick.h"
#include <assert.h>





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

bool Brick::CheckCollision(const Ball & ball) const
{	
	RectF ballHitbox = ball.GetHitbox();
	if (!isDestroyed && rect.IsOverlappingWith(ballHitbox))
	{
		return true;
	}
	else {
		return false;
	}
	
}

void Brick::ExecuteCollision(Ball & ball)
{
	assert(CheckCollision(ball));
	
		bool verticalSuperiorCollision = false;
		bool verticalInferiorCollision = false;
		bool horizontalLeftCollision = false;
		bool horizontalRightCollision = false;
		bool betweenX = false;
		bool betweenY = false;
		Vec2 ballCenter = ball.ReturnCenter();

		 betweenX = ballCenter.x >= rect.left && ballCenter.x <= rect.right;
		 betweenY = ballCenter.y >= rect.top && ballCenter.y <= rect.bottom;
		/* ----------------------- COLISIONES BÁSICAS ------------------------*/
		if ((ballCenter.y < rect.top && ballCenter.y < rect.bottom) && betweenX ) 
		{
			verticalSuperiorCollision = true;
		} else 
			if ((ballCenter.y > rect.top && ballCenter.y > rect.bottom) && betweenX ) 
			{
				verticalInferiorCollision = true;
			}

		if ((ballCenter.x < rect.left && ballCenter.x < rect.right) && betweenY) 
		{
			horizontalLeftCollision = true;
		}
		else
			if ((ballCenter.x > rect.left && ballCenter.x > rect.right) && betweenY ) 
			{
				horizontalRightCollision = true;
			}

		if (verticalInferiorCollision || verticalSuperiorCollision) {
			ball.ReboundY();
			isDestroyed = true;
		} 
		else
		if (horizontalLeftCollision || horizontalRightCollision) {
			ball.ReboundX();
			isDestroyed = true;
		}
		else
			/* ----------------------- COLISIONES ESQUINERAS ------------------------*/
		{
			Vec2 brickBallVector = ball.ReturnCenter() - ReturnCenter();
			if (std::signbit(ball.ReturnVelocity().x) == std::signbit(brickBallVector.x))
			{
				ball.ReboundY();
				isDestroyed = true;
			}
			else
			{
				ball.ReboundX();
				isDestroyed = true;
			}
			
						
		}
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

Vec2 Brick::ReturnCenter() const
{
	float centerX = rect.topLeft.x + ((rect.right - rect.left) / 2.0f);
	float centerY = rect.topLeft.y +((rect.bottom - rect.top) / 2.0f);
	return Vec2(centerX,centerY);
}



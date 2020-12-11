#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
	
public:
	Brick() = default;
	Brick(const Vec2 & topLeft_in, const float width_in, const float height_in, const Color& c_in);

	void Draw(Graphics& gfx ) const;
	void DoBallCollision(Ball& ball);
	bool IsDestroyed() const;
	

private:
	RectF rect;
	Color c;
	bool isDestroyed = false;
	
};


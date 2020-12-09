#pragma once
#include "RectF.h"
#include "Graphics.h"

class Brick
{
	
public:
	Brick(const Vec2 & topLeft_in, const float width_in, const float height_in, const Color& c_in);
	void Draw(Graphics& gfx ) const;

private:
	RectF rect;
	Color c;
};


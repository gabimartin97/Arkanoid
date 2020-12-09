#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "SpriteCodex.h"


class Ball
{
public:
	Ball(const Vec2& center, const Vec2& velocity_in);
	void Draw(Graphics& gfx);


private:
	Vec2 position;
	Vec2 velocity;

};

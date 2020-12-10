#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "SpriteCodex.h"


class Ball
{
public:
	Ball(const Vec2& center, const Vec2& velocity_in);
	void Draw(Graphics& gfx)const;
	void Update(const float dt);
	void DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();

private:
	Vec2 position_center;
	Vec2 velocity;
	static constexpr int radius = 7;
};

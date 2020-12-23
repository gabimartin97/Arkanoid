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
	bool DoWallCollision(const RectF& walls, bool* isGameOver);
	void ReboundX();
	void ReboundY();
	RectF GetHitbox()const;
	void BallHitboxDraw(Graphics& gfx)const;
	Vec2 ReturnCenter() const;
	Vec2 ReturnVelocity() const;
	void ScaleVelocityVector(const Vec2& velocity_in);
	void Move(const Vec2& center_in); 
	float ReturnRadius() const;
private:
	Vec2 position_center;
	Vec2 velocity;
	RectF hitbox;
	float speed = 500;
	
	static constexpr float radius = 7.0f;
	
};

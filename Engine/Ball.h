#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Wall.h"


class Ball
{
public:
	Ball(const Vec2& center, const Vec2& velocity_in);
	bool DoWallCollision(const Wall& walls, bool* isGameOver);
	RectF GetHitbox()const;
	Vec2 ReturnCenter() const;
	Vec2 ReturnVelocity() const;
	float ReturnRadius() const;
	void Draw(Graphics& gfx)const;
	void BallHitboxDraw(Graphics& gfx)const;
	void Update(const float dt);
	void Move(const Vec2& center_in);
	void ReboundX();
	void ReboundY();
	void ScaleVelocityVector(const Vec2& velocity_in);
	void IncreaseSpeed(const float step);
	void SetSpeed(const float speed_in);
		
private:
	Vec2 position_center;
	Vec2 velocity;
	RectF hitbox;
	float speed = 500;
	
	static constexpr float radius = 7.0f;
	
};

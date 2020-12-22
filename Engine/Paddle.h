#pragma once
#include "RectF.h"
#include "Ball.h"
#include "Keyboard.h"


class Paddle {

public:
	Paddle(const Vec2& topLeft_in, const float width_in, const float height_in, Color c_in);
	void Draw(Graphics& gfx)const;
	void Update(const float dt, const unsigned char data);
	void DoWallCollision(const RectF& walls);
	bool DoBallCollision(Ball& ball);
	Vec2 ReturnCenter() const;
	void DeactivateCooldown();
	bool DoVectorialBallCollision(Ball& ball);
	float ReturnHeight()const;

private:
	
	RectF body;
	Color c;
	 float padWidth;
	 float padHeight;
	static constexpr float lateralSpeed = 400;
	bool isCooldown = false;




};
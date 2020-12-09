#pragma once
#include "Vec2.h"

class RectF {

public:
	RectF(const Vec2& topLeft_in, const Vec2& bottomRight_in);
	RectF(const Vec2& topLeft_in, const float width, const float height);

	static RectF FromCenter(const Vec2& center, const float halfWidth, const float halfHeight); // Maneja la sobrecarga de constructor
	//Constructor con center + half width + half height
	Vec2 topLeft;
	Vec2 bottomRight;
private:
	


};
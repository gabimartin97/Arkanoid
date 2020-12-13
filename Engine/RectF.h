#pragma once
#include "Vec2.h"

class RectF {

public:
	RectF() = default;
	RectF(const Vec2& topLeft_in, const Vec2& bottomRight_in);
	RectF(const Vec2& topLeft_in, const float width, const float height);
	void Update(const Vec2& topLeft_in, const Vec2& bottomRight_in);
	bool IsOverlappingWith(const RectF& rect_in)const;
	static RectF FromCenter(const Vec2& center, const float halfWidth, const float halfHeight); // Maneja la sobrecarga de constructor
	RectF GetExpanded( const float scalar) const;
	//Constructor con center + half width + half height
	Vec2 topLeft;
	Vec2 bottomRight;
	float left;
	float right;
	float top;
	float bottom;
private:
	


};
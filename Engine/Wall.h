#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include <assert.h>
class Wall 
{
	
public:
	Wall(const Vec2& screenCenter);
	static constexpr int thickness = 10;
	static constexpr int wallsWidth = 700 ;
	static constexpr int wallsHeight = 550;
	
	RectF borders;
	void Draw(Graphics& gfx)const;
private:
	
};
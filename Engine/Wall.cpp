#include "Wall.h"
#include "Graphics.h"

Wall::Wall(const Vec2& screenCenter)
	:
	borders(Vec2((screenCenter.x - (wallsWidth/2)) , (screenCenter.y - (wallsHeight / 2))), Vec2((screenCenter.x + (wallsWidth / 2)), (screenCenter.y + (wallsHeight / 2))))
{	
	assert((wallsWidth + (2 * thickness)) <= Graphics::ScreenWidth);
	assert((wallsHeight + (2 * thickness)) <= Graphics::ScreenHeight);
}

void Wall::Draw(Graphics & gfx) const
{
	const RectF expandedBorders = borders.GetExpanded(int(thickness));
	gfx.DrawRectContour(expandedBorders, thickness, Colors::Gray);
}

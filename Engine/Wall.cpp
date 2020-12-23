#include "Wall.h"

Wall::Wall(const Vec2& screenCenter)
	:
	borders(Vec2((screenCenter.x - (wallsWidth/2)) , (screenCenter.y - (wallsHeight / 2))), Vec2((screenCenter.x + (wallsWidth / 2)), (screenCenter.y + (wallsHeight / 2))))
{	
}

void Wall::Draw(Graphics & gfx) const
{
	const RectF expandedBorders = borders.GetExpanded(int(thickness));
	gfx.DrawRectContour(expandedBorders, thickness, Colors::Gray);
}

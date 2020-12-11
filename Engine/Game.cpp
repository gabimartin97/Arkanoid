/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	//ladrillin(Vec2(100.0f, 100.0f), 100.0f, 50.0f, Colors::Blue),
	ball(Vec2(300, 400), Vec2(200, -200)),
	walls(Vec2(0,0),Vec2(int(gfx.ScreenWidth),int(gfx.ScreenHeight)))
	
{
	int offsetX = 100;
	int offsetY = 100;
	int i = 0;

	for (int k = 0; k < nBrickRows; k++) {
		for (int j = 0; j < nBrickColumns; j++) {

			bricks[i] = Brick(Vec2(offsetX + brickWidth * j, offsetY + brickHeight * k), brickWidth, brickHeight, Colors::Blue);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt=ft.Mark();
	ball.Update(dt);
	ball.DoWallCollision(walls);
	for (Brick& b : bricks)
	{
		if (!b.IsDestroyed())b.DoBallCollision(ball);
		
	}
	
	
}

void Game::ComposeFrame()
{
	for (const Brick& b : bricks)
	{
		if (!b.IsDestroyed())b.Draw(gfx);
	}
	
	ball.Draw(gfx);
}

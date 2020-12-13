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
	ball(Vec2(300.0f, 400.0f), Vec2(-200.0f, -200.0f)),
	pad(Vec2(400.0f, 520.0f), 80.0f, 25.0f, Colors::Magenta),
	walls(Vec2(0, 0), Vec2(int(gfx.ScreenWidth), int(gfx.ScreenHeight))),
	padHitSound(L"Sounds\\arkpad.wav"),
	brickHitSound(L"Sounds\\arkbrick.wav")
	
{
	int offsetX = 100;
	int offsetY = 100;
	int i = 0;
	Color brickColors[3] = { Colors::Red, Colors::Green, Colors::Blue };
	for (int k = 0; k < nBrickRows; k++) {
		for (int j = 0; j < nBrickColumns; j++) {

			bricks[i] = Brick(Vec2(float(offsetX + brickWidth * j),float( offsetY + brickHeight * k)), float(brickWidth), float(brickHeight), brickColors[k]);
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
	float dt = ft.Mark();
	/*---------------------PAD-----------------------------*/
	if (!wnd.kbd.KeyIsEmpty()) {
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			unsigned char data = 'l';
			pad.Update(dt, data );
			
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {

			unsigned char data = 'r';
			pad.Update(dt, data);
			
		}
	}
	pad.DoWallCollision(walls);
	if (pad.DoBallCollision(ball))padHitSound.Play();
	/*---------------------PAD-----------------------------*/

	ball.Update(dt);
	ball.DoWallCollision(walls);

	for (Brick& b : bricks) { 
		if (!b.IsDestroyed()) { 
			if (b.DoBallCollision(ball)) brickHitSound.Play();
		}
	}
	
	
}
void Game::ComposeFrame()
{
	for (const Brick& b : bricks)
	{
		if (!b.IsDestroyed()) {
			gfx.DrawRect(b.GetExpanded(-2), b.GetColor());
		}
	}
	pad.Draw(gfx);
	//ball.BallHitboxDraw(gfx);
	ball.Draw(gfx);
	
}

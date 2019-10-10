#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprites.h"

CGameObject::CGameObject()
{
	currentState = MOVE_TOP;
	x = y = 0;
	vx = 0.1f;
	vy = 0;
}

void CGameObject::Update(DWORD dt, float width, float height)
{
	x += vx*dt;
	y += vy*dt;
	
	/*switch(currentState)
	{
	case MOVE_TOP:
		if (x < width - 30)
		{
			x += vx * dt;
		}
		else
		{
			x = width - 30;
			currentState = MOVE_RIGHT;
		}
	case MOVE_RIGHT:
		if (y < height)
		{
			y += vy * dt;
		}
		else
		{
			y = height;
			currentState = MOVE_BOTTOM;
		}
	case MOVE_BOTTOM:
		if (x > 0)
		{
			x += -vx * dt;
		}
		else
		{
			x = 0;
			currentState = MOVE_LEFT;
		}
	case MOVE_LEFT:
		if (y > 0)
		{
			y += -vy * dt;
		}
		else
		{
			y = 0;
			currentState = MOVE_TOP;
		}
	}*/
	//if ((vx > 0 && x > 290) || (x < 0 && vx < 0)) vx = -vx;
	// quẹo xuống
	if (vx > 0 && x > width-30)
	{
		vy = 0.1f;
		vx = 0;
		y += vy * dt;
	}
	// dưới quẹo qua trái
	if (vy > 0 && y > height-55)
	{
		vy = 0;
		vx = -0.1f;
		x += vx * dt;
	}
	// dưới trái quẹo lên
	if (vx < 0 && x < 0)
	{
		vx = 0;
		vy = -0.1f;
		y += vy * dt;
	}
	
	if (vy < 0 && y < 2)
	{
		vx = 0.1f;
		vy = 0;
		x += vx * dt;
	}
}

void CGameObject::Render()
{
	LPANIMATION ani;
	//if (vx>0) ani = animations[0]; else ani = animations[1];
	ani = animations[0];
	ani->Render(x, y);
}

void CGameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}



CGameObject::~CGameObject()
{
}
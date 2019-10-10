#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"

#define MOVE_TOP 0
#define MOVE_RIGHT 1
#define MOVE_BOTTOM 2
#define MOVE_LEFT 3




using namespace std;

class CGameObject
{
	float x; 
	float y;

	float vx;
	float vy;

	int currentState;

	vector<LPANIMATION> animations;

public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetState(int state) { this->currentState = state; }
	void AddAnimation(int aniId);

	CGameObject();

	void Update(DWORD dt, float width, float height);
	void Render();
	~CGameObject();
};
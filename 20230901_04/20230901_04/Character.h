#pragma once
//#include "MainGame.h"
class Character
{
public:
	int _x, _y;
	int _animationIndex;
	int _animationTime;
	bool _isJumping;
	bool _isAir;
	int _jumpDuration;
	int _jumpTimer;

	void Init();
	void Update(int deltaTime, char inputKey);
	//자기자신을 그리는 함수
	void Render();
	//자기자신을 지우는 함수
	void Erase();

	void Release();

	void Jump();
	void Move(int x);
};


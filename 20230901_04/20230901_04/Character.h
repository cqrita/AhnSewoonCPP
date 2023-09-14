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
	//�ڱ��ڽ��� �׸��� �Լ�
	void Render();
	//�ڱ��ڽ��� ����� �Լ�
	void Erase();

	void Release();

	void Jump();
	void Move(int x);
};

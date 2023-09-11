#pragma once
#include<vector>
class Character;
struct Star
{
	int _x;
	int _y;
};
class MainGame
{
public:
	//������ => �ּҰ�
	Character* _character;
	vector<Star> _stars;
	int _starDuration;
	int _starTimer;
	int _moveDuration;
	int _moveTimer;
	int _score;
	bool _isGameEnd;
	void Init();
	void Update(int deltaTime);
	void Release();

	bool IsGameEnd();
};


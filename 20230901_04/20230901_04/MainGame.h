#pragma once
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
	Star _star;
	int _score;
	bool _isGameEnd;
	void Init();
	void Update(int deltaTime);
	void Release();

	bool IsGameEnd();
};


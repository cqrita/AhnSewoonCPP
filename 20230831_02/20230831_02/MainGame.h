#pragma once
class Character;
class MainGame
{
public:
	Character* _character;
	bool _isGameEnd = false;
	void Init();
	void Update();
	void Release();
	bool IsGameEnd();
};


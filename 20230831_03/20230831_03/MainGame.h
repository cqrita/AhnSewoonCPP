#pragma once
class Player;
class MainGame
{
public:
	Player* player;
	Player* com;
	int turn=0;
	MainGame();
	~MainGame();
	void Init();
	void Update();
	void Release();
	bool IsGameEnd();
};


#pragma once
class Player;
class MainGame
{
	Player* player;
	Player* com;
	int turn;
	void Init();
	void Update();
	void Release();
};


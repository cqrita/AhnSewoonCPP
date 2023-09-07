#pragma once
class Hand;
class MainGame
{
private:
	vector<Hand*> _hands;
	eGameState _state;
	int _set;

public:
	Hand* GetHand(eHandKind kind);
	eGameState GetState();
	int GetSet();
	void Init();
	void Update_Pick();
	void Update();
	void Release();
	bool IsGameEnd();
};
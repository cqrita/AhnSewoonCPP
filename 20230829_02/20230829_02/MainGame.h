#pragma once
enum eBetChoice
{
	BETCHOICE_HIGH,
	BETCHOICE_LOW, 
	BETCHOICE_SEVEN,
	BETCHOICE_NOBET, 
	BETCHOICE_END

};
class MainGame
{
public:

	// card 52
	//player betting
	//player bet
	//current card index

	int _card[52];
	int _playerGold;

	int _playerBet;
	int _betChoice;
	int _currentCardIndex;

	//Initialize
	void Init();
	//Update
	void Update();
	//Check cameend
	bool IsGameEnd();
	//Release
	void Release();
};


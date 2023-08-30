#pragma once
class MainGame
{
public:
	int card[52];
	int player[10];
	int dealer[10];
	int playerSum;
	int dealerSum;
	int cardIndex;
	int playerIndex;
	int dealerIndex;
	int turn;
	bool stand;
	//초기화
	void Init();
	//업데이트
	void Update();
	//해제
	void Release();

	//게임이 끝났는지 체크
	bool IsGameEnd();
	bool gameEnd;

	int SumCards(int cards[]);
	void PrintHands(bool Stand);
	void HandCards(int& index, int hand[]);
};


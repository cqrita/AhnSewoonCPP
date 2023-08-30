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
	//�ʱ�ȭ
	void Init();
	//������Ʈ
	void Update();
	//����
	void Release();

	//������ �������� üũ
	bool IsGameEnd();
	bool gameEnd;

	int SumCards(int cards[]);
	void PrintHands(bool Stand);
	void HandCards(int& index, int hand[]);
};


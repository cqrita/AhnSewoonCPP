#include "main.h"
#include "MainGame.h"
#include "CardUtil.h"
void MainGame::Init()
{
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		_card[i] = i;
	}
	_playerGold = 10000;
	_playerBet = 0;
	_betChoice = BETCHOICE_END;
	_currentCardIndex = 4;

	for (int i = 0; i < 100000; i++)
	{
		int num1 = rand() % 52;
		int num2 = rand() % 52;
		int temp = _card[num1];
		_card[num1] = _card[num2];
		_card[num2] = temp;
	}
}
void MainGame::Update()
{
	system("cls");
	// 4 cards
	//player petting
	//player type
	//_card[_currentcardindex]
	// if low and select low
	// if high and select high
	// if seven and select seven
	// else
	cout << "setted cards : ";
	for (int i = 4; i >= 1; i--)
	{
		PrintCard(_card[_currentCardIndex - i]);
		cout << "\t";
	}
	cout << "??" << endl;
	cout << "player current gold : " << _playerGold << endl;
	cout << "Player Bet? yes 0 or no 1" << endl;
	int input;
	cin >> input;
	if (input == 0)
	{
		cout << "select betting type : (0:high 1:low 2: seven) : " << endl;
		cin >> _betChoice;
		cout << "betting gold : ";
		cin >> _playerBet;

		if (_playerGold < _playerBet)
		{
			_playerBet = _playerGold;
		}
		_playerGold = _playerGold - _playerBet;
	}
	else
	{
		_betChoice = BETCHOICE_NOBET;
	}

	cout << "this card : ";
	PrintCard(_card[_currentCardIndex]);
	cout << endl;
	int cardNum = _card[_currentCardIndex] % 13 + 1;
	if (cardNum == 7 && _betChoice == BETCHOICE_SEVEN)
	{
		cout << "congrats" << endl;
		_playerGold = _playerBet * 10;
	}
	else if (cardNum <7 && _betChoice == BETCHOICE_LOW)
	{
		cout << "congrats" << endl;
		_playerGold = _playerBet * 2;
	}
	else if (cardNum > 7 && _betChoice == BETCHOICE_HIGH)
	{
		cout << "congrats" << endl;
		_playerGold = _playerBet * 2;
	}
	else
	{
		cout << "Next Time" << endl;
	}
	_currentCardIndex++;
	system("pause");
}

bool MainGame::IsGameEnd()
{
	return _currentCardIndex==52||_playerGold<=0;
}

void MainGame::Release()
{
	
}
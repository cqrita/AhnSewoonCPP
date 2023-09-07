#include "stdafx.h"
#include "MainGame.h"
#include "Hand.h"

Hand* MainGame::GetHand(eHandKind kind)
{
	return _hands[(int)kind];
}

eGameState MainGame::GetState()
{
	return _state;
}

int MainGame::GetSet()
{
	return _set;
}

void MainGame::Init()
{
	cout << "MainGame::Init()" << endl;

	//1. 유저수만큼 Hands를 만든다.
	//2. _state를 GAMESTATE_PICK 로 변경한다.

	for (int i = 0; i < HANDKIND_END; i++)
	{
		Hand* newHand = new Hand();
		newHand->Init();

		_hands.push_back(newHand);
	}

}

void MainGame::Update_Pick()
{
	//1. 컴퓨터와 플레이어손을 고른다.
	int input = 0;
	cout << "플레이어 고를 손을 골라주세요(0:바위 1:가위 2:보)" << endl;
	cin >> input;
	_set++;
	_hands[HANDKIND_PLAYER]->SetMyHand(input);
	//10판을하면 1판은 무조건 컴퓨터가 이겨야한다.
	_hands[HANDKIND_COMPUTER]->SetComHand();

	_state = GAMESTATE_SHOW;
}

void MainGame::Update()
{
	cout << "MainGame::Update()" << endl;
	switch (_state)
	{
	case GAMESTATE_PICK:
	{
		Update_Pick();
		break;
	}
	case GAMESTATE_SHOW:
	{
		//1. 컴퓨터와 플레이어 손을 보여준다.
		cout << "내가 고른것 : " << _hands[HANDKIND_PLAYER]->GetHandName() << endl;
		cout << "상대가 고른것 : " << _hands[HANDKIND_COMPUTER]->GetHandName() << endl;

		_state = GAMESTATE_RESULT;
		break;
	}
	case GAMESTATE_RESULT:
	{
		//2. 누가이겼는지 보여준다.
		cout << "누군가 이겼다" << endl;

		/*if (_hands[HANDKIND_PLAYER]->GetHand() == RSP_ROCK && _hands[HANDKIND_COMPUTER]->GetHand() == RSP_PAPER)
		{

		}*/
		_state = GAMESTATE_PICK;
		break;
	}
	case GAMESTATE_END:
	{
		break;
	}
	default:
		break;
	}

}
void MainGame::Release()
{
	cout << "MainGame::Release()" << endl;


	for (int i = 0; i < _hands.size(); i++)
	{
		_hands[i]->Release();
		delete _hands[i];
		_hands[i] = nullptr;
	}
	_hands.clear();
}

bool MainGame::IsGameEnd()
{
	//state가 End면 게임 종료
	return _state == eGameState::GAMESTATE_END;
}
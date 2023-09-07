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

	//1. ��������ŭ Hands�� �����.
	//2. _state�� GAMESTATE_PICK �� �����Ѵ�.

	for (int i = 0; i < HANDKIND_END; i++)
	{
		Hand* newHand = new Hand();
		newHand->Init();

		_hands.push_back(newHand);
	}

}

void MainGame::Update_Pick()
{
	//1. ��ǻ�Ϳ� �÷��̾���� ����.
	int input = 0;
	cout << "�÷��̾� �� ���� ����ּ���(0:���� 1:���� 2:��)" << endl;
	cin >> input;
	_set++;
	_hands[HANDKIND_PLAYER]->SetMyHand(input);
	//10�����ϸ� 1���� ������ ��ǻ�Ͱ� �̰ܾ��Ѵ�.
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
		//1. ��ǻ�Ϳ� �÷��̾� ���� �����ش�.
		cout << "���� ���� : " << _hands[HANDKIND_PLAYER]->GetHandName() << endl;
		cout << "��밡 ���� : " << _hands[HANDKIND_COMPUTER]->GetHandName() << endl;

		_state = GAMESTATE_RESULT;
		break;
	}
	case GAMESTATE_RESULT:
	{
		//2. �����̰���� �����ش�.
		cout << "������ �̰��" << endl;

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
	//state�� End�� ���� ����
	return _state == eGameState::GAMESTATE_END;
}
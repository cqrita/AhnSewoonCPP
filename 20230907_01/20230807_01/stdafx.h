#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum eRockScissorPaper
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,
	RSP_END
};

enum eHandKind
{
	HANDKIND_PLAYER,
	HANDKIND_COMPUTER,
	HANDKIND_END
};

//���� ����
enum eGameState
{
	//�÷��̾ ����������, ��ǻ�� ������ ���� �����ܰ�
	GAMESTATE_PICK,
	//���� ������ �´��� �����ִ� ����
	GAMESTATE_SHOW,
	//���� �̰���� �����ִ� ����
	GAMESTATE_RESULT,

	GAMESTATE_END
};

#include "MainGame.h"
#include "Hand.h"
extern MainGame* _mainGame;
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

//게임 상태
enum eGameState
{
	//플레이어가 무엇을낼지, 컴퓨가 무엇을 낼지 결정단계
	GAMESTATE_PICK,
	//각각 무엇을 냈는지 보여주는 상태
	GAMESTATE_SHOW,
	//누가 이겼는지 보여주는 상태
	GAMESTATE_RESULT,

	GAMESTATE_END
};

#include "MainGame.h"
#include "Hand.h"
extern MainGame* _mainGame;
#include "stdafx.h"

MainGame* _mainGame = nullptr;
//역할 정리
//객체 5원칙
//첫 번째가
//단일책임원칙
//하나의 클래스에서 여러가지 일을 하지 말아라
//하나의 임무만 지어라

//Hand
// -> 손
//  => SetHand(int hand) (내가 어떤손을 낼지)
//  => GetHand() (내가 어떤손을 냈는지)
//MainGame
// => 가위바위보게임 룰
//		SetHands(); 컴퓨터는 랜덤손을 낸다.
//		SetHands(); 유저는 입력받은 손을 낸다.
//		ShowHands(); 각자 무엇을 냈는지 UI에 출력한다.
//		ShowResult(); 누가 이겼는지 UI에 보여준다.



void main() 
{
	srand(time(NULL));
	//5. 가위바위보 class화
	_mainGame = new MainGame();
	_mainGame->Init();

	while (false == _mainGame->IsGameEnd())
	{
		_mainGame->Update();
	}

	_mainGame->Release();
	delete _mainGame;
	_mainGame = nullptr;

}
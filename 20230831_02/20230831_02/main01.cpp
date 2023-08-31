#include "stdafx.h"


void main()
{
	//타이틀을 설정한다.
	CustomConsole.SetTitle("가위바위보");

	//글자색을 변경한다.
	CustomConsole.SetTextColor(LIGHTGREEN);

	//글자색의 BackGround색을 변경한다.
	CustomConsole.SetBkColor(GRAY);

	//커서를 없앤다.
	CustomConsole.SetCursor(tvision::CURSOR_OFF);

	//윈도우 사이즈를 조정한다.
	CustomConsole.SetWindowSize(100, 30);
	//윈도우 전체 사이즈를 조정한다.
	CustomConsole.SetScreenFufferSize(100, 30);

	MainGame* mainGame = new MainGame();
	while (mainGame->IsGameEnd()==false)
	{
		mainGame->Update();
	}
	delete mainGame;
	mainGame = nullptr;
}
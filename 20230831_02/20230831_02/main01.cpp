#include "stdafx.h"


void main()
{
	//Ÿ��Ʋ�� �����Ѵ�.
	CustomConsole.SetTitle("����������");

	//���ڻ��� �����Ѵ�.
	CustomConsole.SetTextColor(LIGHTGREEN);

	//���ڻ��� BackGround���� �����Ѵ�.
	CustomConsole.SetBkColor(GRAY);

	//Ŀ���� ���ش�.
	CustomConsole.SetCursor(tvision::CURSOR_OFF);

	//������ ����� �����Ѵ�.
	CustomConsole.SetWindowSize(100, 30);
	//������ ��ü ����� �����Ѵ�.
	CustomConsole.SetScreenFufferSize(100, 30);

	MainGame* mainGame = new MainGame();
	while (mainGame->IsGameEnd()==false)
	{
		mainGame->Update();
	}
	delete mainGame;
	mainGame = nullptr;
}
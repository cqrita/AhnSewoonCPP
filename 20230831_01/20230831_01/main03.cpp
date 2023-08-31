#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
class MainGame
{
public: 
	void Init();
	void Update();
	void Release();

	bool IsGameEnd();
};
void MainGame::Init()
{

}
void MainGame::Update()
{
	
}
void MainGame::Release()
{

}
bool MainGame::IsGameEnd()
{

}
void main()
{
	MainGame* mainGame = new MainGame();
	mainGame->Init();
	while (mainGame->IsGameEnd()==false)
	{
		mainGame->Update();
	}
	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}
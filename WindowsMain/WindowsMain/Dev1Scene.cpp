#include "stdafx.h"
#include "Dev1Scene.h"
#include "Actor.h"
#include "Player.h"
#include "SpriteActor.h"
#include "BoxCollider.h"
void Dev1Scene::Init()
{
	_background = new SpriteActor();
	_background->Init();
	_background->SetSprite(L"../Resources/background.jpg", Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT));
	{
		_player = new Player();
		_player->Init();
		_player->SetPlayerInfo(300, Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 100, 100), L"../Resources/Player Ships/Short-Lazer-Ship.png");
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 100, 100));
			collider->Init();
			_player->AddComponent(collider);
		}
	}
}
void Dev1Scene::Render(HDC hdc)
{
	_background->Render(hdc);
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Render(hdc);
	}
	_player->Render(hdc);
	char str[250];
	sprintf_s(str, "DEV1SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
	//scene objects
}
void Dev1Scene::Update()
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Update();
	}
	_player->Update();
	_background->Update();

}
void Dev1Scene::Release()
{

	_player->Release();
	SAFE_DELETE(_player);

	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Release();
		SAFE_DELETE(_actors[i]);
	}
	_actors.clear();
	_background->Release();
	SAFE_DELETE(_background);
}

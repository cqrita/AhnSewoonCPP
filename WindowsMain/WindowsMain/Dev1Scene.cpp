#include "stdafx.h"
#include "Dev1Scene.h"
#include "Actor.h"
#include "Player.h"
#include "GdiSpriteActor.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Texture.h"
#include "BoxCollider.h"
#include "ItemBox.h"
#include "TrackingMonster.h"
void Dev1Scene::Init()
{
	_background = new GdiSpriteActor();
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
	{
		TrackingMonster* trackingMonster = new TrackingMonster();
		trackingMonster->Init();
		trackingMonster->SetTrackingMonsterInfo(PI/3.0f,50,Vector2(100,100), Vector2::Down());
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 50, 50));
			collider->Init();
			trackingMonster->AddComponent(collider);
		}
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(trackingMonster);
		trackingMonster->SetTargetActor(_player);
	}
	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->Init();
		spriteActor->SetBody(Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2 + 100, WIN_SIZE_HEIGHT / 2 + 100, 50, 50));
		Texture* texture=GET_SINGLE(ResourceManager)->LoadTexture("texture", "Player Ships/Short-Lazer-Ship.png");
		Sprite* sprite=GET_SINGLE(ResourceManager)->CreateSprite("sprite", texture);
		spriteActor->SetSprite(sprite);
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(spriteActor);
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

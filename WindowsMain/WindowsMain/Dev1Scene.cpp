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
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CameraComponent.h"

void Dev1Scene::Init()
{
	SetPlayerResource();
	Texture* texture=GET_SINGLE(ResourceManager)->LoadTexture("T_background", "background.jpg", RGB(255, 0, 255));
	Sprite* sprite=GET_SINGLE(ResourceManager)->CreateSprite("S_background", texture);

	_background = new SpriteActor();
	_background->Init();
	_background->SetSprite(sprite);
	_background->SetBody(Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, WIN_SIZE_WIDTH*2, WIN_SIZE_HEIGHT*2));
	{
		_player = new Player();
		_player->Init();
		_player->SetPlayerInfo(500, Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 200, 200));
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 100, 100));
			_player->AddComponent(collider);
		}
		{
			CameraComponent* camera = new CameraComponent();
			_player->AddComponent(camera);
		}
	}
	{
		TrackingMonster* trackingMonster = new TrackingMonster();
		trackingMonster->Init();
		trackingMonster->SetTrackingMonsterInfo(PI/3.0f,50,Vector2(100,100), Vector2::Down());
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 50, 50));
			trackingMonster->AddComponent(collider);
		}
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(trackingMonster);
		trackingMonster->SetTargetActor(_player);
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

void Dev1Scene::SetPlayerResource()
{
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Down", "Character/PlayerDown.bmp", RGB(128, 128, 128));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Down", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Down", info);
	}
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Up", "Character/PlayerUp.bmp", RGB(128, 128, 128));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Up", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Up", info);
	}
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Left", "Character/PlayerLeft.bmp", RGB(128, 128, 128));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Left", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Left", info);
	}
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Right", "Character/PlayerRight.bmp", RGB(128, 128, 128));
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Right", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Right", info);
	}
}

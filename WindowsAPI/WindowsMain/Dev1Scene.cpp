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
#include "Button.h";
#include "TestPanel.h"
#include "CircleCollider.h"
#include "Wall.h"
void Dev1Scene::Init()
{

	Super::Init();

	SetPlayerResource();
	Texture* texture=GET_SINGLE(ResourceManager)->LoadTexture("T_background", "background.jpg", RGB(255, 0, 255));
	Sprite* sprite=GET_SINGLE(ResourceManager)->CreateSprite("S_background", texture);

	_background = new SpriteActor();
	_background->SetLayer(LayerType::Background);
	_background->SetSprite(sprite);
	_background->SetBody(Rect::MakeCenterRect(WIN_SIZE_WIDTH * 1.5, 0, WIN_SIZE_WIDTH * 5, WIN_SIZE_HEIGHT));
	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_background);
	_speed = 1000;
	{
		_player = new Player();
		_player->SetPlayerInfo(_speed, Rect::MakeCenterRect(-350, -200, 200, 200));
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 50,60));
			collider->SetCollisionLayer(CollisionLayerType::CLT_OBJECT);
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_OBJECT);
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_WALL);
			_player->AddComponent(collider);
		}
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_player);
	}
	vector<RECT> walls = GET_SINGLE(DataManager)->GetCollisionData();
	for (RECT rc : walls)
	{
		Wall* wall = new Wall();
		wall->SetWallInfo(rc);
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(wall);
	}
	SetCameraPos(Vector2Int(-100,0));
	_level = 1;
	_score = 0;
}
void Dev1Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	char str[250];
	sprintf_s(str, "DEV1SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
	string scoreStr = "SCORE : " + to_string(_score);
	TextOut(hdc, WIN_SIZE_WIDTH - 120, 0, scoreStr.c_str(), scoreStr.size());
	string levelStr = "LEVEL : " + to_string(_level);
	TextOut(hdc, WIN_SIZE_WIDTH - 80, 20, levelStr.c_str(), levelStr.size());

	//scene objects
}
void Dev1Scene::Update()
{
	Super::Update();
	Vector2 camera = GetCameraPos();
	camera.x += _speed/1000;
	camera.x = clamp<float>(camera.x, -100, WIN_SIZE_WIDTH * 4);
	SetCameraPos(camera);
	_score += DeltaTime;
	if (_player->GetBody().x >= WIN_SIZE_WIDTH * 3)
	{
		_speed * 1.1;
		_level++;
		_player->SetPlayerInfo(_speed, Rect::MakeCenterRect(-330, -200, 200, 200));
		SetCameraPos(Vector2Int());
	}
	if (_player->GetBody().x<GetCameraPos().x - WIN_SIZE_WIDTH/2 || _player->GetBody().x > GetCameraPos().x + WIN_SIZE_WIDTH/2
		|| _player->GetBody().y < GetCameraPos().y - WIN_SIZE_HEIGHT/2 || _player->GetBody().y > GetCameraPos().y + WIN_SIZE_HEIGHT/2)
	{
		MessageBox(_hwnd, ("SCORE : "+to_string(_score)).c_str(), "GAME END!", NULL);
		PostQuitMessage(0);
	}
}
void Dev1Scene::Release()
{
	Super::Release();
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
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Down", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 5;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Down", info);
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
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Up", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 5;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Up", info);
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
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Left", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 5;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Left", info);
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
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Right", info);
	}
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 5;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };
		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Right", info);
	}

	{
		Texture* texture = GET_SINGLE(ResourceManager)->LoadTexture("T_StartButton", "Buttons/Start.bmp", RGB(255, 0, 210));
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Default", texture,0,0,200,200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Hover", texture, 200, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Pressed", texture, 400, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Disabled", texture, 600, 0, 200, 200);


	}



}
void Dev1Scene::ChangeScene()
{
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
}

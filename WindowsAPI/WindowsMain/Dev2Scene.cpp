#include "stdafx.h"
#include "Dev2Scene.h"
#include "BackgroundActor.h"
#include "Player.h"
#include "BoxCollider.h"
void Dev2Scene::Init()
{
	Super::Init();
	_background = new BackgroundActor();
	_background->SetSpeed(300);
	_background->SetSize(Vector2(1200, WIN_SIZE_HEIGHT));
	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_background);
	_player = new Player();
	_player->SetPlayerInfo(Rect::MakeCenterRect(-WIN_SIZE_WIDTH/4-100, 0, 50, 50));
	{
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Rect::MakeCenterRect(0, 0, 50, 50));
		collider->SetCollisionLayer(CollisionLayerType::CLT_OBJECT);
		collider->AddCollisionFlagLayer(CollisionLayerType::CLT_OBJECT);
		collider->AddCollisionFlagLayer(CollisionLayerType::CLT_WALL);
		_player->AddComponent(collider);
	}

	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_player);
}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	char str[250];
	sprintf_s(str, "DEV2SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT-50, str, strlen(str));
}
void Dev2Scene::Update()
{
	Super::Update();

}
void Dev2Scene::Release()
{
	Super::Release();
}

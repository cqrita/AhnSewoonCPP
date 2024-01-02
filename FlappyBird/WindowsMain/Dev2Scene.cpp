#include "stdafx.h"
#include "Dev2Scene.h"
#include "BackgroundActor.h"
#include "Player.h"
#include "BoxCollider.h"
#include <string>
void Dev2Scene::Init()
{
	Super::Init();
	_background = new BackgroundActor();
	_background->SetSpeed(300);
	_background->SetSize(Vector2(1200, WIN_SIZE_HEIGHT));
	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_background);
	_player = new Player();
	_player->SetPlayerInfo(Rect::MakeCenterRect(-WIN_SIZE_WIDTH/4-100, 0, 50, 50),-9.8,250);

	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_player);
}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	char str[250];
	sprintf_s(str, "DEV2SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT-50, str, strlen(str));
	string score = "score : " + to_string(_player->GetScore());
	TextOut(hdc, WIN_SIZE_WIDTH-80,10, score.c_str(), score.size());

}
void Dev2Scene::Update()
{
	Super::Update();

}
void Dev2Scene::Release()
{
	Super::Release();
}

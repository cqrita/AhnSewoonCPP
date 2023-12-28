#include "stdafx.h"
#include "Dev2Scene.h"
#include "BackgroundActor.h"
void Dev2Scene::Init()
{
	Super::Init();
	_background = new BackgroundActor();
	_background->SetSpeed(500);
	_background->SetSize(Vector2(800, WIN_SIZE_HEIGHT));
	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_background);

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

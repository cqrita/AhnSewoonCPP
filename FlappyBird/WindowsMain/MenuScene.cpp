#include "stdafx.h"
#include "MenuScene.h"
#include "BackgroundActor.h"
#include "Texture.h"
#include "Sprite.h"
#include "SpriteActor.h"
#include "Button.h"
void MenuScene::Init()
{
	Super::Init();
	_background = new BackgroundActor();
	_background->SetSpeed(300);
	_background->SetSize(Vector2(1200, WIN_SIZE_HEIGHT));
	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_background);

	Texture* titleTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_title", "image/splash/title_name.bmp", RGB(255, 0, 255));
	Sprite* titleSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_title", titleTexture);
	_title = new SpriteActor();
	_title->SetLayer(LayerType::Object);
	_title->SetSprite(titleSprite);
	_title->SetBody(Rect::MakeCenterRect(0, -WIN_SIZE_HEIGHT / 4, WIN_SIZE_WIDTH/4, WIN_SIZE_HEIGHT/8));
	GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_title);

	Texture* startNormalTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_startNormal", "image/splash/game_start_normal.bmp", RGB(255, 0, 255));
	Sprite* startNormalSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_startNormal", startNormalTexture);
	Texture* startPressTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_startPress", "image/splash/game_start_press.bmp", RGB(255, 0, 255));
	Sprite* startPressSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_startPress", startPressTexture);

	_button = new Button();
	_button->SetSprite(eButtonState::Default, startNormalSprite);
	_button->SetSprite(eButtonState::Pressed, startPressSprite);
	_button->SetRect(Rect::MakeCenterRect(WIN_SIZE_WIDTH/2, WIN_SIZE_HEIGHT / 2, WIN_SIZE_WIDTH/4 , WIN_SIZE_HEIGHT/8));
	_button->Init();
	_button->AddOnClickDelegate(this, &MenuScene::ChangeScene);
	_UIs.push_back(_button);

}
void MenuScene::Render(HDC hdc)
{
	Super::Render(hdc);
	char str[250];
	sprintf_s(str, "MENUSCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
}
void MenuScene::Update()
{
	Super::Update();
}
void MenuScene::Release()
{
	Super::Release();
}

void MenuScene::ChangeScene()
{
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
}

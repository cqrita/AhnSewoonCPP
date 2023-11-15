#include "stdafx.h"
#include "MaptoolPanel.h"
#include "Button.h"
#include "Texture.h"
#include "MapToolScene.h"
MaptoolPanel::MaptoolPanel()
{

}

MaptoolPanel::~MaptoolPanel()
{

}

void MaptoolPanel::Init()
{
	Super::Init();

	{
		Texture* texture = GET_SINGLE(ResourceManager)->LoadTexture("T_StartButton", "Buttons/Start.bmp", RGB(255, 0, 210));
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Default", texture, 0, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Hover", texture, 200, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Pressed", texture, 400, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Disabled", texture, 600, 0, 200, 200);

	}
	{
		Button* button = new Button();
		button->SetRect(Rect::MakeCenterRect(WIN_SIZE_WIDTH/2-100, WIN_SIZE_HEIGHT*3/4, 100, 100));
		button->AddOnClickDelegate(this, &MaptoolPanel::OnClick_Save);
		button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
		button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
		button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
		button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
		AddChild(button);
	}
	{
		Button* button = new Button();
		button->SetRect(Rect::MakeCenterRect(WIN_SIZE_WIDTH/2+100, WIN_SIZE_HEIGHT * 3 / 4, 100, 100));
		button->AddOnClickDelegate(this, &MaptoolPanel::OnClick_Revert);
		button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
		button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
		button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
		button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
		AddChild(button);
	}

}

void MaptoolPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}

void MaptoolPanel::Update()
{
	Super::Update();
}

void MaptoolPanel::Release()
{
	Super::Release();
}

void MaptoolPanel::OnClick_Save()
{
	cout << "Save" << endl;
	MapToolScene* mapToolScene = CheckValidation();
	if (mapToolScene == nullptr)
	{
		return;
	}
	mapToolScene->Save();

}

void MaptoolPanel::OnClick_Revert()
{
	cout << "Revert" << endl;
	MapToolScene* mapToolScene = CheckValidation();
	if (mapToolScene == nullptr)
	{
		return;
	}
	mapToolScene->Revert();
}

MapToolScene* MaptoolPanel::CheckValidation()
{
	Scene* scene = GET_SINGLE(SceneManager)->GetCurrentScene();
	MapToolScene* mapToolScene = dynamic_cast<MapToolScene*>(scene);
	if (mapToolScene == nullptr)
	{
		Alert("Error", "Wrong Scene");
		return nullptr;
	}
	return mapToolScene;
}

#include "stdafx.h"
#include "Dev2Scene.h"
#include "Button.h"
#include "SpriteActor.h"
#include "Texture.h"
#include "Wall.h"
void Dev2Scene::Init()
{
	{
		Texture* texture = GET_SINGLE(ResourceManager)->LoadTexture("T_StartButton", "Buttons/Start.bmp", RGB(255, 0, 210));
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Default", texture, 0, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Hover", texture, 200, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Pressed", texture, 400, 0, 200, 200);
		GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Disabled", texture, 600, 0, 200, 200);
	}

	Button* button = new Button();
	button->SetRect(Rect::MakeCenterRect(WIN_SIZE_WIDTH/2-100, WIN_SIZE_HEIGHT/2, 100, 100));
	button->AddOnClickDelegate(this, &Dev2Scene::SaveButton);
	button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
	button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
	button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
	button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
	_UIs.push_back(button);

	Button* button2 = new Button();
	button2->SetRect(Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2 + 100, WIN_SIZE_HEIGHT / 2, 100, 100));
	button2->AddOnClickDelegate(this, &Dev2Scene::ResetButton);
	button2->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
	button2->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
	button2->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
	button2->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
	_UIs.push_back(button2);

	vector<RECT> walls = GET_SINGLE(DataManager)->GetCollisionData();
	for (RECT rc : walls)
	{
		Wall* wall = new Wall();
		wall->SetWallInfo(rc);
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(wall);
	}


	int _cWall = 0;
	_mouseFlag = false;
	Scene::Init();

}
void Dev2Scene::Render(HDC hdc)
{
	Scene::Render(hdc);
	
	char str[250];
	sprintf_s(str, "DEV2SCENE");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT-50, str, strlen(str));
}
void Dev2Scene::Update()
{
	Scene::Update();
	if (Input->GetKeyDown(VK_LBUTTON))
	{
		_mouseFlag = true;
		_mouseRect = RECT{};
		_mouseRect.left= _mousePos.x;
		_mouseRect.top = _mousePos.y;
		_mouseRect.right = _mousePos.x;
		_mouseRect.bottom = _mousePos.y;
		Wall* wall = new Wall();
		wall->SetWallInfo(_mouseRect);
		_walls.push_back(wall);
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(wall);
	}
	if (_mouseFlag == true&&_walls.size()!=0)
	{
		_mouseRect.right = _mousePos.x;
		_mouseRect.bottom = _mousePos.y;
		_walls[_cWall]->SetBody(CenterRect::FromRect(_mouseRect));
		if (Input->GetKeyUp(VK_LBUTTON))
		{
			_mouseFlag = false;
			_rectWalls.push_back(RECT(_mouseRect));
			_cWall++;
		}
	}
}
void Dev2Scene::Release()
{
	Scene::Release();

}

void Dev2Scene::ResetButton()
{
	for (Wall* wall : _walls)
	{
		GET_SINGLE(SceneManager)->GetCurrentScene()->DeSpawnActor(wall);
	}
	_rectWalls.clear();
	_walls.clear();
	_cWall = 0;
}

void Dev2Scene::SaveButton()
{
	
	GET_SINGLE(DataManager)->SaveCollisionData(_rectWalls);
	_rectWalls.clear();
	_walls.clear();

}

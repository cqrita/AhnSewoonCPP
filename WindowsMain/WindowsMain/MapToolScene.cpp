#include "stdafx.h"
#include "MapToolScene.h"
#include "MaptoolPanel.h"
#include "SpriteActor.h"
#include "Texture.h"
#include "Sprite.h"

void MapToolScene::Init()
{
	{
		SpriteActor* background = new SpriteActor();
		background->SetLayer(LayerType::Background);
		Texture* texture = GET_SINGLE(ResourceManager)->LoadTexture("T_background", "Background/backround_supermario.bmp", RGB(255, 0, 255));
		Sprite* sprite = GET_SINGLE(ResourceManager)->CreateSprite("S_background", texture);
		background->SetSprite(sprite);
		background->SetBody(Rect::MakeCenterRect(WIN_SIZE_WIDTH*3.5, 0, WIN_SIZE_WIDTH*8, WIN_SIZE_HEIGHT));
		SpawnActor(background);
	}
	{
		Panel* panel = new MaptoolPanel();
		_UIs.push_back(panel);
	}
	Super::Init();
	_state = MapToolState::IDLE;
	_wallVec = GET_SINGLE(DataManager)->GetCollisionData();
}

void MapToolScene::Render(HDC hdc)
{
	Super::Render(hdc);
	for (RECT rc : _wallVec)
	{
		Draw::Rect(hdc, rc,GetCameraPos());
	}
	Draw::Rect(hdc, _currentRect, GetCameraPos());
	switch (_state)
	{
	case MapToolState::IDLE:
		RenderIdle(hdc);
		break;
	case MapToolState::WALL_MAKE:
		RenderWallMake(hdc);
		break;
	default:
		break;
	}

	char str[250];
	sprintf_s(str, "MapToolScene");
	TextOut(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));

}

void MapToolScene::Update()
{
	Super::Update();
	UpdateInput();
	switch (_state)
	{
	case MapToolState::IDLE:
		UpdateIdle();
		break;
	case MapToolState::WALL_MAKE:
		UpdateWallMake();
		break;
	default:
		break;
	}
}

void MapToolScene::Release()
{
	Super::Release();
}

void MapToolScene::UpdateInput()
{
	if (GET_SINGLE(KeyManager)->GetKey(VK_RIGHT))
	{
		Vector2Int camera= GetCameraPos();
		SetCameraPos(camera + Vector2Int(1, 0));
	}
}

void MapToolScene::UpdateIdle()
{
	if (GET_SINGLE(KeyManager)->GetKeyDown('Q'))
	{
		_state = MapToolState::WALL_MAKE;
		_currentRect.left = _mousePos.x+GetCameraPos().x-WIN_SIZE_WIDTH/2;
		_currentRect.top = _mousePos.y + GetCameraPos().y - WIN_SIZE_HEIGHT/2;
		_currentRect.right = _mousePos.x + GetCameraPos().x - WIN_SIZE_WIDTH / 2;
		_currentRect.bottom = _mousePos.y + GetCameraPos().y - WIN_SIZE_HEIGHT / 2;
	}
}

void MapToolScene::UpdateWallMake()
{
	_currentRect.right = _mousePos.x + GetCameraPos().x - WIN_SIZE_WIDTH / 2;
	_currentRect.bottom = _mousePos.y + GetCameraPos().y - WIN_SIZE_HEIGHT / 2;
	if (GET_SINGLE(KeyManager)->GetKeyDown('Q'))
	{
		_state = MapToolState::IDLE;
		Rect::ChangeToNormalValue(_currentRect);
		_wallVec.push_back(_currentRect);
		_currentRect={};
	}

}

void MapToolScene::RenderIdle(HDC hdc)
{
	char str[250];
	sprintf_s(str, "Press Q To Start");
	TextOut(hdc, WIN_SIZE_WIDTH - 300, 0, str, strlen(str));
}

void MapToolScene::RenderWallMake(HDC hdc)
{
	char str[250];
	sprintf_s(str, "Press Q To End");
	TextOut(hdc, WIN_SIZE_WIDTH - 300, 0, str, strlen(str));
}

void MapToolScene::Revert()
{
	if (_wallVec.size() > 0)
	{
		_wallVec.pop_back();
	}
}

void MapToolScene::Save()
{
	GET_SINGLE(DataManager)->ClearCollisionData();
	if (_wallVec.size() > 0)
	{
		GET_SINGLE(DataManager)->SaveCollisionData(_wallVec);

	}
}

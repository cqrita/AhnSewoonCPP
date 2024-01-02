#include "stdafx.h"
#include "PipeActor.h"
#include "SpriteActor.h"
#include "Wall.h"
#include "Sprite.h"
#include "Texture.h"
#include "Scene.h"

void PipeActor::Init()
{
	Super::Init();
	Texture* obstacleUpTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_obstacleUp", "image/obstacle_up1.bmp", RGB(255, 0, 255));
	Sprite* obstacleUpSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_obstacleUp", obstacleUpTexture);

	Texture* obstacleDownTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_obstacleDown", "image/obstacle_down1.bmp", RGB(255, 0, 255));
	Sprite* obstacleDownSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_obstacleDown", obstacleDownTexture);

	for (int i = 0; i < 16; i++)
	{
		int randNum = rand() % (int)(_size.y / 4);
		_up[i] = new Wall();
		_up[i]->SetLayer(LayerType::Background);
		_up[i]->SetSprite(obstacleUpSprite);
		_up[i]->SetBody(Rect::MakeCenterRect((_size.x / 4) * i + 300, -_size.y / 2 - randNum - _width, 100, _size.y));
		_up[i]->SetWallInfo();
		_up[i]->Init();


		_down[i] = new Wall();
		_down[i]->SetLayer(LayerType::Background);
		_down[i]->SetSprite(obstacleDownSprite);
		_down[i]->SetBody(Rect::MakeCenterRect((_size.x / 4) * i + 300, _size.y / 2 - randNum + _width, 100, _size.y));
		_down[i]->SetWallInfo();
		_down[i]->Init();
	}
}

void PipeActor::Render(HDC hdc)
{
	Super::Render(hdc);
	if (GET_SINGLE(SceneManager)->GetCurrentSceneType() == SceneType::Dev2Scene)
	{
		for (int i = 0; i < 16; i++)
		{
			_up[i]->Render(hdc);
			_down[i]->Render(hdc);
		}
	}

}

void PipeActor::Update()
{
	Super::Update();

	for (int i = 0; i < 16; i++)
	{
		_up[i]->Update();
		_down[i]->Update();
	}

	for (int i = 0; i < 16; i++)
	{
		CenterRect body = _up[i]->GetBody();
		_up[i]->SetBody(Rect::MakeCenterRect(body.x - _speed * DeltaTime, body.y, body.width, body.height));
	}
	for (int i = 0; i < 16; i++)
	{
		CenterRect body = _down[i]->GetBody();
		_down[i]->SetBody(Rect::MakeCenterRect(body.x - _speed * DeltaTime, body.y, body.width, body.height));
	}

	for (int i = 0; i < 16; i++)
	{
		int randNum = rand() % (int)(_size.y / 4);
		{
			CenterRect body = _up[i]->GetBody();
			if (_up[i]->GetBody().x < -_size.x)
			{
				_up[i]->SetBody(Rect::MakeCenterRect(body.x + (_size.x * 4), -_size.y / 2 - randNum - _width, body.width, body.height));
			}
		}
		{
			CenterRect body = _down[i]->GetBody();
			if (_down[i]->GetBody().x < -_size.x)
			{
				_down[i]->SetBody(Rect::MakeCenterRect(body.x + (_size.x * 4), _size.y / 2 - randNum + _width, body.width, body.height));
			}
		}
	}

}

void PipeActor::Release()
{
	Super::Release();
	for (int i = 0; i < 16; i++)
	{
		_up[i]->Release();
		_down[i]->Release();
	}
}

void PipeActor::SetWidth(float width)
{
	_width=width;
}

void PipeActor::SetSize(Vector2 size)
{
	_size = size;
}

void PipeActor::SetSpeed(int speed)
{
	_speed = speed;
}

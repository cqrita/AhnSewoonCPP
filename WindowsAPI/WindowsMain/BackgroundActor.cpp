#include "stdafx.h"
#include "BackgroundActor.h"
#include "SpriteActor.h"
#include "Wall.h"
#include "Sprite.h"
#include "Texture.h"
#include "Scene.h"
void BackgroundActor::Init()
{
	Super::Init();
	Texture* backgroundTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_background", "image/background.bmp", RGB(255, 0, 255));
	Sprite* backgroundSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_background", backgroundTexture);

	Texture* bottomTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_bottom", "image/bottom.bmp", RGB(255, 0, 255));
	Sprite* bottomSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_bottom", bottomTexture);

	Texture* obstacleUpTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_obstacleUp", "image/obstacle_up.bmp", RGB(255, 0, 255));
	Sprite* obstacleUpSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_obstacleUp", obstacleUpTexture);

	Texture* obstacleDownTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_obstacleDown", "image/obstacle_down.bmp", RGB(255, 0, 255));
	Sprite* obstacleDownSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_obstacleDown", obstacleDownTexture);

	for (int i = 0; i < 8; i++)
	{
		_background[i] = new SpriteActor();
		_background[i]->SetLayer(LayerType::Background);
		_background[i]->SetSprite(backgroundSprite);
		_background[i]->SetBody(Rect::MakeCenterRect(-_size.x / 4 + (_size.x / 4) * i, 0, _size.x / 2, _size.y));
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_background[i]);

		_bottom[i] = new Wall();
		_bottom[i]->SetLayer(LayerType::Background);
		_bottom[i]->SetSprite(bottomSprite);
		_bottom[i]->SetBody(Rect::MakeCenterRect(-_size.x / 4 + (_size.x / 4) * i, _size.y / 2, _size.x / 2, _size.y / 2));
		_bottom[i]->SetWallInfo();
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_bottom[i]);

	}
	for (int i = 0; i < 16; i++)
	{
		int randNum = rand() % (int)(_size.y / 4);
		_up[i] = new Wall();
		_up[i]->SetLayer(LayerType::Background);
		_up[i]->SetSprite(obstacleUpSprite);
		_up[i]->SetBody(Rect::MakeCenterRect((_size.x / 4) * i+300, -_size.y / 2 - randNum-140, 100, _size.y));
		_up[i]->SetWallInfo();
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_up[i]);

		_down[i] = new Wall();
		_down[i]->SetLayer(LayerType::Background);
		_down[i]->SetSprite(obstacleDownSprite);
		_down[i]->SetBody(Rect::MakeCenterRect((_size.x / 4) * i+300, _size.y / 2- randNum+140, 100, _size.y));
		_down[i]->SetWallInfo();
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_down[i]);

	}
}

void BackgroundActor::Render(HDC hdc)
{
	Super::Render(hdc);
}

void BackgroundActor::Update()
{
	Super::Update();
	for (int i = 0; i < 8; i++)
	{
		CenterRect body = _background[i]->GetBody();
		_background[i]->SetBody(Rect::MakeCenterRect(body.x - _speed * DeltaTime, body.y, body.width, body.height));
	}
	for (int i = 0; i < 8; i++)
	{
		CenterRect body = _background[i]->GetBody();
		if (_background[i]->GetBody().x < -_size.x)
		{
			_background[i]->SetBody(Rect::MakeCenterRect(body.x + (_size.x * 2) - 0.5, body.y, body.width, body.height));
		}
	}

	for (int i = 0; i < 8; i++)
	{
		CenterRect body = _bottom[i]->GetBody();
		_bottom[i]->SetBody(Rect::MakeCenterRect(body.x - _speed * DeltaTime, body.y, body.width, body.height));
	}
	for (int i = 0; i < 8; i++)
	{
		CenterRect body = _bottom[i]->GetBody();
		if (_bottom[i]->GetBody().x < -_size.x)
		{
			_bottom[i]->SetBody(Rect::MakeCenterRect(body.x + (_size.x * 2) - 0.5, body.y, body.width, body.height));
		}

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
				_up[i]->SetBody(Rect::MakeCenterRect(body.x + (_size.x*4), -_size.y / 2 - randNum - 140, body.width, body.height));
			}
		}
		{
			CenterRect body = _down[i]->GetBody();
			if (_down[i]->GetBody().x < -_size.x)
			{
				_down[i]->SetBody(Rect::MakeCenterRect(body.x + (_size.x*4), _size.y / 2 - randNum + 140, body.width, body.height));
			}
		}
	}


}

void BackgroundActor::Release()
{
	Super::Release();
}

void BackgroundActor::SetSpeed(int speed)
{
	_speed = speed;
}

void BackgroundActor::SetSize(Vector2 size)
{
	_size = size;
}

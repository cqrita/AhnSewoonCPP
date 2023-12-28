#include "stdafx.h"
#include "BackgroundActor.h"
#include "SpriteActor.h"
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

	for (int i = 0; i < 8; i++)
	{
		_background[i] = new SpriteActor();
		_background[i]->SetLayer(LayerType::Background);
		_background[i]->SetSprite(backgroundSprite);
		_background[i]->SetBody(Rect::MakeCenterRect(-_size.x / 4 + (_size.x / 4) * i, 0, _size.x / 2, _size.y));
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_background[i]);

		_bottom[i] = new SpriteActor();
		_bottom[i]->SetLayer(LayerType::Background);
		_bottom[i]->SetSprite(bottomSprite);
		_bottom[i]->SetBody(Rect::MakeCenterRect(-_size.x / 4 + (_size.x / 4) * i, _size.y / 2, _size.x / 2, _size.y / 2));
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(_bottom[i]);
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

#include "stdafx.h"
#include "BackgroundActor.h"
#include "SpriteActor.h"
#include "Wall.h"
#include "Sprite.h"
#include "Texture.h"
#include "Scene.h"
#include "PipeActor.h"
void BackgroundActor::Init()
{
	Super::Init();
	Texture* backgroundTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_background", "image/background.bmp", RGB(255, 0, 255));
	Sprite* backgroundSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_background", backgroundTexture);

	Texture* bottomTexture = GET_SINGLE(ResourceManager)->LoadTexture("T_bottom", "image/bottom.bmp", RGB(255, 0, 255));
	Sprite* bottomSprite = GET_SINGLE(ResourceManager)->CreateSprite("S_bottom", bottomTexture);

	for (int i = 0; i < 8; i++)
	{
		BackgroundLayer* backgroundLayer = new BackgroundLayer();
		backgroundLayer->Sky = new SpriteActor();;
		backgroundLayer->Sky->SetLayer(LayerType::Background);
		backgroundLayer->Sky->SetSprite(backgroundSprite);
		backgroundLayer->Sky->SetBody(Rect::MakeCenterRect(-_size.x / 4 + (_size.x / 4) * i, 0, _size.x / 2, _size.y));
		backgroundLayer->Sky->Init();

		backgroundLayer->Ground = new Wall();
		backgroundLayer->Ground->SetLayer(LayerType::Background);
		backgroundLayer->Ground->SetSprite(bottomSprite);
		backgroundLayer->Ground->SetBody(Rect::MakeCenterRect(-_size.x / 4 + (_size.x / 4) * i, _size.y / 2, _size.x / 2, _size.y / 2));
		backgroundLayer->Ground->SetWallInfo();
		backgroundLayer->Ground->Init();
		_backgroundLayer.push_back(backgroundLayer);
	}
	_pipe = new PipeActor();
	_pipe->SetSpeed(300);
	_pipe->SetSize(Vector2(1200, WIN_SIZE_HEIGHT));
	_pipe->SetWidth(140);
	_pipe->Init();
}

void BackgroundActor::Render(HDC hdc)
{
	Super::Render(hdc);
	for (int i = 0; i < _backgroundLayer.size(); i++)
	{
		_backgroundLayer[i]->Sky->Render(hdc);
	}
	_pipe->Render(hdc);
	for (int i = 0; i < _backgroundLayer.size(); i++)
	{
		_backgroundLayer[i]->Ground->Render(hdc);
	}
}

void BackgroundActor::Update()
{
	Super::Update();
	for (int i = 0; i < _backgroundLayer.size(); i++)
	{
		_backgroundLayer[i]->Sky->Update();
		_backgroundLayer[i]->Ground->Update();
	}


	for (int i = 0; i < _backgroundLayer.size(); i++)
	{
		CenterRect skyBody = _backgroundLayer[i]->Sky->GetBody();
		_backgroundLayer[i]->Sky->SetBody(Rect::MakeCenterRect(skyBody.x - _speed * DeltaTime, skyBody.y, skyBody.width, skyBody.height));
		CenterRect GroundBody = _backgroundLayer[i]->Ground->GetBody();
		_backgroundLayer[i]->Ground->SetBody(Rect::MakeCenterRect(GroundBody.x - _speed * DeltaTime, GroundBody.y, GroundBody.width, GroundBody.height));
	}
	for (int i = 0; i < _backgroundLayer.size(); i++)
	{
		CenterRect skyBody = _backgroundLayer[i]->Sky->GetBody();
		CenterRect GroundBody = _backgroundLayer[i]->Ground->GetBody();

		if (_backgroundLayer[i]->Sky->GetBody().x < -_size.x)
		{
			_backgroundLayer[i]->Sky->SetBody(Rect::MakeCenterRect(skyBody.x + (_size.x * 2) - 0.5, skyBody.y, skyBody.width, skyBody.height));
			_backgroundLayer[i]->Ground->SetBody(Rect::MakeCenterRect(GroundBody.x + (_size.x * 2) - 0.5, GroundBody.y, GroundBody.width, GroundBody.height));
		}
	}
	_pipe->Update();
}

void BackgroundActor::Release()
{
	Super::Release();
	for (int i = 0; i < _backgroundLayer.size(); i++)
	{
		_backgroundLayer[i]->Sky->Release();
		_backgroundLayer[i]->Ground->Release();
		delete _backgroundLayer[i]->Sky;
		delete _backgroundLayer[i]->Ground;
		delete _backgroundLayer[i];
	}
	_pipe->Release();
	delete _pipe;
}

void BackgroundActor::SetSpeed(int speed)
{
	_speed = speed;
}

void BackgroundActor::SetSize(Vector2 size)
{
	_size = size;
}

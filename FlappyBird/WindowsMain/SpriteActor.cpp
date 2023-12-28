#include "stdafx.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Scene.h"
void SpriteActor::Init()
{
	Super::Init();
}

void SpriteActor::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_sprite == nullptr)
	{
		return;
	}
	Vector2Int size = _sprite->GetSize();
	BLENDFUNCTION bf;
	bf.AlphaFormat = AC_SRC_ALPHA; 

	bf.BlendFlags = 0; 

	bf.BlendOp = AC_SRC_OVER;

	bf.SourceConstantAlpha = _sprite->GetTransparent();
	Vector2Int CameraPos = CurrentScene->GetCameraPos();
	CameraPos -= Vector2Int(WIN_SIZE_WIDTH/2, WIN_SIZE_HEIGHT / 2);
	AlphaBlend(hdc, (int)(_body.x - _body.width/2)-CameraPos.x, (int)(_body.y - _body.height/2) - CameraPos.y,
		(int)(_body.width), (int)(_body.height), _sprite->GetDC(), _sprite->GetPos().x, _sprite->GetPos().y, size.x, size.y, bf);
}

void SpriteActor::Update()
{
	Super::Update();
}

void SpriteActor::Release()
{
	Super::Release();
}

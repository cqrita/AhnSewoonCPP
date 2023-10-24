#include "stdafx.h"
#include "SpriteActor.h"
#include "Sprite.h"
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
	BitBlt(hdc, (int)(_body.x - _body.width), (int)(_body.y - _body.height),
		size.x, size.y, _sprite->GetDC(), _sprite->GetPos().x, _sprite->GetPos().y, SRCCOPY);
}

void SpriteActor::Update()
{
	Super::Update();
}

void SpriteActor::Release()
{
	Super::Release();
}

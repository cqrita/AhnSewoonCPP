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

	TransparentBlt(hdc, (int)(_body.x - _body.width/2), (int)(_body.y - _body.height/2),
		(int)(_body.width), (int)(_body.height), _sprite->GetDC(), _sprite->GetPos().x, _sprite->GetPos().y, size.x, size.y,_sprite->GetTransparent());
}

void SpriteActor::Update()
{
	Super::Update();
}

void SpriteActor::Release()
{
	Super::Release();
}

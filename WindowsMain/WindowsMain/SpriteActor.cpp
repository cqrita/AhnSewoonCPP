#include "stdafx.h"
#include "SpriteActor.h"
void SpriteActor::Init()
{
	Super::Init();

}
void SpriteActor::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_sprite)
	{
		Gdiplus::Graphics g(hdc);
		g.DrawImage(_sprite, _body.ToGdiRect());
	}
}
void SpriteActor::Update()
{
	Super::Update();

}
void SpriteActor::Release()
{
	Super::Release();

}
void SpriteActor::SetSprite(const WCHAR* fliePath, CenterRect drawArea)
{
	_sprite = Gdiplus::Image::FromFile(fliePath);
	_body = drawArea;
}
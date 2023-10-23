#include "stdafx.h"
#include "SpriteActor.h"
void SpriteActor::Init()
{
	Super::Init();

}
void SpriteActor::Render(HDC hdc)
{
	static Gdiplus::Graphics* g=nullptr;
	static HDC lastHdc = {};


	if (lastHdc!=hdc)
	{
		SAFE_DELETE(g);
		g = new Gdiplus::Graphics(hdc);
		g->SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		lastHdc = hdc;
	}

	Super::Render(hdc);
	if (_sprite)
	{
		if (false == (abs(_rotationRadian) < EPSILON))
		{
			{
				Gdiplus::Matrix matrix;
				matrix.RotateAt(Rad2Deg(_rotationRadian), Gdiplus::PointF(_body.x, _body.y));
				g->SetTransform(&matrix);
			}
			g->DrawImage(_sprite, _body.ToGdiRect());
			{
				Gdiplus::Matrix matrix;
				g->SetTransform(&matrix);
			}
		}
		else
		{
			g->DrawImage(_sprite, _body.ToGdiRect());
		}
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
	_sprite = Gdiplus::Bitmap::FromFile(fliePath, false);
	_body = drawArea;
}
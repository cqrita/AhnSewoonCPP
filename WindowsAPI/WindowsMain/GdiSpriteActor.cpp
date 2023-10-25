#include "stdafx.h"
#include "GdiSpriteActor.h"
void GdiSpriteActor::Init()
{
	Super::Init();
}
void GdiSpriteActor::Render(HDC hdc)
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
void GdiSpriteActor::Update()
{
	Super::Update();

}
void GdiSpriteActor::Release()
{
	Super::Release();

}
void GdiSpriteActor::SetSprite(const WCHAR* fliePath, CenterRect drawArea)
{
	_sprite = Gdiplus::Bitmap::FromFile(fliePath, false);
	_body = drawArea;
}
#include "stdafx.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "Texture.h"
#include "Scene.h"
void FlipbookActor::Init()
{
	Super::Init();
}

void FlipbookActor::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_flipbook == nullptr)
	{
		return;
	}
	const FlipbookInfo& info= _flipbook->GetInfo();
	Vector2Int size = info.size;

	BLENDFUNCTION bf;

	bf.AlphaFormat = AC_SRC_ALPHA;

	bf.BlendFlags = 0;

	bf.BlendOp = AC_SRC_OVER;

	bf.SourceConstantAlpha = info.texture->GetTransparent();
	Vector2Int CameraPos = CurrentScene->GetCameraPos();
	CameraPos -= Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

	TransparentBlt(hdc, (int)(_body.x - _body.width / 2) - CameraPos.x, (int)(_body.y - _body.height / 2) - CameraPos.y,
		(int)(_body.width), (int)(_body.height),
		info.texture->GetDc(), (info.start + _index) * info.size.x, info.line * size.y, size.x, size.y, info.texture->GetTransparent());
}

void FlipbookActor::Update()
{
	Super::Update();
	if (_flipbook == nullptr)
	{
		return;
	}
	const FlipbookInfo& info = _flipbook->GetInfo();
	_sumTime += DeltaTime;
	int frameAmount = (info.end - info.start + 1);
	float delta = info.duration / frameAmount;
	if (delta <= _sumTime)
	{
		_sumTime -= delta;
		_index++;
		_index %= frameAmount;
	}
}

void FlipbookActor::Release()
{
	Super::Release();
}

void FlipbookActor::Reset()
{
	_sumTime = 0.0f;
	_index = 0;
}

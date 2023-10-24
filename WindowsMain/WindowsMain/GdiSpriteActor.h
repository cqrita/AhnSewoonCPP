#pragma once
#include "Actor.h"
class GdiSpriteActor :public Actor
{
protected:
	Gdiplus::Bitmap* _sprite=nullptr;
public:
	void SetSprite(const WCHAR* fliePath, CenterRect _body);
public:
	using Super = Actor;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};


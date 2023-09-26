#pragma once
#include "Actor.h"
class SpriteActor :public Actor
{
protected:
	class Gdiplus::Image* _sprite=nullptr;
	CenterRect _body = {};
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


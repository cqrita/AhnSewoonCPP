#pragma once
#include "Actor.h"
class Wall : public Actor
{
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void SetWallInfo(RECT rc);
};


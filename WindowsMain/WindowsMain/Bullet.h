#pragma once
#include "SpriteActor.h"
class Bullet :public SpriteActor
{
public:
	using Super = SpriteActor;
private:
	int _speed;
	Vector2 _direction;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetBulletInfo(Vector2 direction,int speed, CenterRect body, const WCHAR* spritePath);

};


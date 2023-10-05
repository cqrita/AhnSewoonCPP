#pragma once
#include "SpriteActor.h"
class Player : public SpriteActor
{
public:
	using Super = SpriteActor;
private:
	int _speed;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(int speed, CenterRect body, const WCHAR* spritePath);
public:
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;

};


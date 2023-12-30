#pragma once
#include "Actor.h"
class SpriteActor : public Actor
{
protected:
	class Sprite* _sprite = nullptr;
public:
	void SetSprite(Sprite* sprite) { _sprite = sprite; }
	const class Sprite* GetSprite() { return _sprite;}
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

};


#pragma once
#include "SpriteActor.h"
class Player : public SpriteActor
{
public:
	using Super = SpriteActor;
private:
	int _speed;
	vector<class Bullet*> _bullets;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(int speed, CenterRect body, const WCHAR* spritePath);
	void DeleteBullet(int i) { _bullets.erase(_bullets.begin() + i); };
	vector<class Bullet*> GetBullets() const { return _bullets; };
};


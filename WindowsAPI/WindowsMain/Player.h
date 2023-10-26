#pragma once
#include "FlipbookActor.h"
enum class ePlayerDirection :int
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
	END
};
class Player : public FlipbookActor
{
public:
	using Super = FlipbookActor;
private:
	int _speed;
	Flipbook* _idleFlipbook[4];
	Flipbook* _moveFlipbook[4];
	Flipbook* _attackFlipbook[4];
	class Sword* _sword;
	bool _isAttacking;
	ePlayerDirection _spriteDir= ePlayerDirection::END;
	int DirToInt(ePlayerDirection dir) { return static_cast<int>(dir); }
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(int speed, CenterRect body);
public:
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;

};


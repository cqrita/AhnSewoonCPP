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
enum class ePlayerState
{
	Idle,
	Move,
	Attack,
	Hit,


	End
};
class Player : public FlipbookActor
{
public:
	using Super = FlipbookActor;
private:
	int _speed;
	int _missileStat;
	bool _IsAttackFlag;
	bool _IsAttack;
	bool _onHit;
	Flipbook* _idleFlipbook[4];
	Flipbook* _moveFlipbook[4];
	Flipbook* _attackFlipbook[4];
	Flipbook* _hitFlipbook[4];
	Vector2 _direction;
	ePlayerDirection _spriteDir= ePlayerDirection::END;
	ePlayerState _state = ePlayerState::Idle;

	int DirToInt(ePlayerDirection dir) { return static_cast<int>(dir); }
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetPlayerInfo(int speed, CenterRect body);
	void SetState(ePlayerState state);
	ePlayerState GetState() { return _state; }
public:
	void UpdateInput();
	void UpdateMove();
	void UpdateIdle();
	void UpdateAttack();
	void UpdateHit();
	bool CanChangeDirection();
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;
	
};


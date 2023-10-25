#pragma once
#include "SpriteActor.h"
class TrackingMonster : public SpriteActor
{
public:
	using Super = SpriteActor;
private:
	int _speed;
	Vector2 _direction;
	Vector2 _originDirection;

	float _trackingRadian;
	Actor* _targetActor=nullptr;
	Vector2 _originPos;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void Move(Vector2 direction);
	void SetTrackingMonsterInfo(float trackingRadian, int speed,Vector2 spawnPos,Vector2 direction);
	void SetTargetActor(Actor* targetActor);
	bool IsInTrackingRange();
};


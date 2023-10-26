#pragma once
#include "Actor.h"
class Sword : public Actor
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;
public:
	void SetSwordInfo(Vector2 spawnPos);
};


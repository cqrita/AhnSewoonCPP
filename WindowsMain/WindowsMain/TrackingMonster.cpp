#include "stdafx.h"
#include "TrackingMonster.h"
void TrackingMonster::Init()
{
	Super::Init();
}
void TrackingMonster::Render(HDC hdc)
{
	Super::Render(hdc);
	Vector2 forwardDirection = _direction.Normalize();
	Vector2 leftDirection = Vector2(-forwardDirection.y, forwardDirection.x);
	Vector2 rightDirection = Vector2(forwardDirection.y, -forwardDirection.x);

	Vector2 leftEndPos = Vector2(_body.x, _body.y) + (forwardDirection * cos(_trackingRadian / 2) + leftDirection * sin(_trackingRadian / 2)) * 200;
	Vector2 rightEndPos = Vector2(_body.x, _body.y) + (forwardDirection * cos(_trackingRadian / 2) + rightDirection * sin(_trackingRadian / 2)) * 200;
	Draw::Line(hdc, Vector2(_body.x, _body.y), leftEndPos);
	Draw::Line(hdc, Vector2(_body.x, _body.y), rightEndPos);
}
void TrackingMonster::Update()
{
	Super::Update();
	// init remember starting 
	//if target actor
	// if in
	//move
	//else
	// move to starting
	if (_targetActor)
	{
		if (IsInTrackingRange())
		{
			Vector2 moveVec = (_targetActor->GetBody().Position() - this->GetBody().Position()).Normalize();
			this->_direction = _direction*0.95f+moveVec*0.05f;
			Move(moveVec);
		}
		else
		{
			Vector2 toTarget = (_originPos - this->GetBody().Position());
			if (toTarget.Length() > 2.0f)
			{
				Vector2 moveVec = toTarget.Normalize();
				this->_direction = _direction * 0.95f + moveVec * 0.05f;
				Move(moveVec);
			}
			else
			{
				this->_direction = _direction*0.95f+_originDirection*0.05f;
			}
		}
	}
	_rotationRadian = Vector2::Down().SignedAngle(this->_direction);

}
void TrackingMonster::Release()
{
	Super::Release();
}

void TrackingMonster::Move(Vector2 direction)
{
	direction.Normalize();
	_body.x += direction.x * _speed * DeltaTime;
	_body.y += direction.y * _speed * DeltaTime;
}
void TrackingMonster::SetTrackingMonsterInfo(float trackingRadian, int speed, Vector2 spawnPos, Vector2 direction)
{
	_direction = direction;
	_originDirection = direction;
	_speed = speed;
	_trackingRadian = trackingRadian;
	_originPos = spawnPos;
	SetSprite(L"../Resources/Enemies/Enemy_02.png",Rect::MakeCenterRect(spawnPos.x,spawnPos.y,70,70));
}
void TrackingMonster::SetTargetActor(Actor* targetActor)
{
	_targetActor = targetActor;
}
bool TrackingMonster::IsInTrackingRange()
{
	float distance = (_targetActor->GetBody().Position() - this->GetBody().Position()).Length();
	if (distance < 200)
	{
		float signedAngle = (_direction).SignedAngle(_targetActor->GetBody().Position() - this->GetBody().Position());
		if (abs(signedAngle) < _trackingRadian / 2)
		{
			return true;
		}
	}
	return false;
}
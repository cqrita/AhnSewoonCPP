#include "stdafx.h"
#include "BoxCollider.h"
#include "Actor.h"
void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush =SelectBrush(hdc, emptyBrush);

	Draw::Rect(hdc, GetCollision());
	SelectBrush(hdc, oldBrush);
	DeleteBrush(emptyBrush);
}
void BoxCollider::Update()
{
	Super::Update();

}
void BoxCollider::Release()
{
	Super::Release();
}
bool BoxCollider::CheckCollision(Collider* other)
{
	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
		break;
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		CenterRect otherCollision = otherCollider->GetCollision();
		return Collision::RectInRect(this->GetCollision(), otherCollision);
		break;
	}
	}
}
BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
	_collision = {};
}

BoxCollider::~BoxCollider() 
{

}
CenterRect BoxCollider::GetCollision()
{
	CenterRect body = GetOwner()->GetBody();
	CenterRect worldCollision = Rect::MakeCenterRect(body.x + _collision.x, body.y + _collision.y, _collision.width, _collision.height);
	return worldCollision;
}
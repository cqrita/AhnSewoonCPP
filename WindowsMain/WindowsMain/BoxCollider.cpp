#include "stdafx.h"
#include "BoxCollider.h"
#include "Actor.h"
#include "Scene.h"
void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush =SelectBrush(hdc, emptyBrush);
	CenterRect worldRect = GetCollision();
	Vector2Int CameraPos = CurrentScene->GetCameraPos();
	CameraPos -= Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

	worldRect.x -= static_cast<float>(CameraPos.x);
	worldRect.y -= static_cast<float>(CameraPos.y);

	Draw::Rect(hdc, worldRect);
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
	if(Super::CheckCollision(other) == false)
	{
		return false;
	}
	else
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
		return false;
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
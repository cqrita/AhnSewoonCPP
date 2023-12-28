#include "stdafx.h"
#include "CircleCollider.h"
#include "Scene.h"
#include "Actor.h"
#include "BoxCollider.h"
CenterCircle CircleCollider::GetCollision()
{
	CenterRect body = GetOwner()->GetBody();
	CenterCircle worldCollision = { Vector2(_collision.center.x + body.x,_collision.center.y + body.y),float(_collision.radius) };
	return worldCollision;
}
void CircleCollider::Init()
{
    Super::Init();
}

void CircleCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush = SelectBrush(hdc, emptyBrush);
	CenterRect worldRect = GetCollision().ToCenterRect();
	Vector2Int CameraPos = CurrentScene->GetCameraPos();
	CameraPos -= Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

	worldRect.x -= static_cast<float>(CameraPos.x);
	worldRect.y -= static_cast<float>(CameraPos.y);

	Draw::Circle(hdc, worldRect);
	SelectBrush(hdc, oldBrush);
	DeleteBrush(emptyBrush);
}

void CircleCollider::Update()
{
	Super::Update();
}

void CircleCollider::Release()
{
	Super::Release();

}

bool CircleCollider::CheckCollision(Collider* other)
{
	if (Super::CheckCollision(other) == false)
	{
		return false;
	}
	else
	{
		switch (other->GetColliderType())
		{
		case ColliderType::Circle:
		{
			CircleCollider* otherCollider = static_cast<CircleCollider*>(other);
			CenterCircle otherCollision = otherCollider->GetCollision();
			return Collision::CircleInCircle(this->GetCollision(), otherCollision);
			break;
		}
		case ColliderType::Box:
		{
			BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
			CenterRect otherCollision = otherCollider->GetCollision();
			return Collision::RectInCircle(otherCollision, this->GetCollision());
			break;
		}
		}
		return false;
	}
}

CircleCollider::CircleCollider() :Collider(ColliderType::Circle)
{
	
}

CircleCollider::~CircleCollider()
{

}

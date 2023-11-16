#include "stdafx.h"
#include "Collider.h"
void Collider::Init()
{
	GET_SINGLE(CollisionManager)->AddCollider(this);
}
void Collider::Render(HDC hdc)
{
	
}
void Collider::Update()
{

}
void Collider::Release()
{
	GET_SINGLE(CollisionManager)->RemoveCollider(this);
}
bool Collider::CheckCollision(Collider* other)
{
	uint8 otherLayer = other->GetCollisionLayer();
	if (_collisionFlag & (1 << otherLayer))
	{
		uint8 myLayer = this->GetCollisionLayer();
		if (other->GetCollisionFlag() & (1 << myLayer))
		{
			return true;
		}
	}
	return false;
}

void Collider::AddCollisionFlagLayer(CollisionLayerType layer)
{
	_collisionFlag |= (1 << layer);
}

void Collider::RemoveCollisionFlagLayer(CollisionLayerType layer)
{
	_collisionFlag &= ~(1 << layer);
}

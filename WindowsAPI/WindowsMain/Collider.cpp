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
	return false;
}
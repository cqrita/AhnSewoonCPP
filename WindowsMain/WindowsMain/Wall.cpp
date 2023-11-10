#include "stdafx.h"
#include "Wall.h"
#include "BoxCollider.h"
void Wall::Init()
{
}

void Wall::Render(HDC hdc)
{
#if _DEBUG
	Draw::Rect(hdc, GetBody());
#endif
}

void Wall::Update()
{
}

void Wall::Release()
{
}

void Wall::SetWallInfo(RECT rc)
{
	SetBody(CenterRect::FromRect(rc));
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(CenterRect::FromRect(rc));
	collider->SetCollisionLayer(CollisionLayerType::CLT_WALL);
	collider->AddCollisionFlagLayer(CollisionLayerType::CLT_OBJECT);
	AddComponent(collider);
}

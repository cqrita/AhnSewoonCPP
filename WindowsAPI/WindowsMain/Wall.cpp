#include "stdafx.h"
#include "Wall.h"
#include "BoxCollider.h"
void Wall::Init()
{
	Super::Init();

}

void Wall::Render(HDC hdc)
{
#if _DEBUG
	Draw::Rect(hdc, GetBody());
#endif
	Super::Render(hdc);
}

void Wall::Update()
{
	Super::Update();
}

void Wall::Release()
{
	Super::Release();
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

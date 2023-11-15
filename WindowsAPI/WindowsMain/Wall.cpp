#include "stdafx.h"
#include "Wall.h"
#include "BoxCollider.h"
#include "Scene.h"
void Wall::Init()
{
	Super::Init();

}

void Wall::Render(HDC hdc)
{
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

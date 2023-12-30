#include "stdafx.h"
#include "Wall.h"
#include "BoxCollider.h"
#include "Scene.h"
void Wall::Init()
{
	Super::Init();
	this->SetName("Wall");
}

void Wall::Render(HDC hdc)
{
	Super::Render(hdc);

	Vector2Int CameraPos = CurrentScene->GetCameraPos();

#if _DEBUG
	//Draw::Rect(hdc, GetBody().ToRect(), CameraPos);
#endif
}

void Wall::Update()
{
	Super::Update();

}

void Wall::Release()
{
	Super::Release();

}

void Wall::SetWallInfo()
{
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Rect::MakeCenterRect(0, 0, _body.width, _body.height));
	collider->SetCollisionLayer(CollisionLayerType::CLT_WALL);
	this->AddComponent(collider);
}

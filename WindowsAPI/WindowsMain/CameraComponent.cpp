#include "stdafx.h"
#include "CameraComponent.h"
#include "Actor.h"
#include "Scene.h"
CameraComponent::CameraComponent()
{

}

CameraComponent::~CameraComponent()
{

}

void CameraComponent::Init()
{
	Super::Init();
	Actor* owner = this->GetOwner();
	if (owner)
	{
		cameraPos = Vector2(owner->GetBody().x, owner->GetBody().y);
		cameraPos.x = clamp<float>(cameraPos.x, 0, WIN_SIZE_WIDTH*7);
		cameraPos.y = clamp<float>(cameraPos.y, -WIN_SIZE_HEIGHT / 2, 0);
	}
}

void CameraComponent::Render(HDC hdc)
{
	Super::Render(hdc);
}

void CameraComponent::Update()
{
	Super::Update();
	Actor* owner = this->GetOwner();
	if (owner)
	{
		Vector2 newCameraPos = Vector2(owner->GetBody().x, owner->GetBody().y);

		cameraPos = Vector2::Lerp(cameraPos, newCameraPos, DeltaTime * 2);
		cameraPos.x = clamp<float>(cameraPos.x, 0, WIN_SIZE_WIDTH*7);
		cameraPos.y = clamp<float>(cameraPos.y, -WIN_SIZE_HEIGHT / 2, 0);

		CurrentScene->SetCameraPos(cameraPos);
	}
}

void CameraComponent::Release()
{
	Super::Release();
}


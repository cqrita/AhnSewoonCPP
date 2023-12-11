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
		cameraPos = Vector2(owner->GetBody().x+300, owner->GetBody().y);
		cameraPos.x = clamp<float>(cameraPos.x, 0, WIN_SIZE_WIDTH * 3);
		cameraPos.y = clamp<float>(cameraPos.y, 0, 0);
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
		Vector2 newCameraPos = Vector2(owner->GetBody().x+300, owner->GetBody().y);
		newCameraPos.x = clamp<float>(newCameraPos.x, 0, WIN_SIZE_WIDTH * 3);
		newCameraPos.y = clamp<float>(newCameraPos.y, 0, 0);
		cout << newCameraPos.y << endl;
		CurrentScene->SetCameraPos(newCameraPos);
	}
}

void CameraComponent::Release()
{
	Super::Release();
}


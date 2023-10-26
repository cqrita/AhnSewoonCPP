#include "stdafx.h"
#include "Sword.h"
#include "Collider.h"
#include "Scene.h"
void Sword::Init()
{
	Actor::Init();
}

void Sword::Update()
{
	Actor::Update();
}

void Sword::Release()
{
	Actor::Release();
}

void Sword::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	if (other->GetOwner()!=nullptr&&other->GetOwner()->GetName() == "Monster")
	{

		other->Release();
		GET_SINGLE(SceneManager)->GetCurrentScene()->DeSpawnActor(other->GetOwner());
	}

}

void Sword::OnComponentEndOverlap(Collider* collider, Collider* other)
{
}

void Sword::SetSwordInfo(Vector2 spawnPos)
{
	_body = Rect::MakeCenterRect(spawnPos.x, spawnPos.y, 1, 1);
}

#include "stdafx.h"
#include "Actor.h"
#include "Component.h"
#include "Collider.h"
void Actor::Init()
{
	for (Component* component : _components)
	{
		component->Init();
	}
}
void Actor::Render(HDC hdc)
{
	for (Component* component : _components)
	{
		component->Render(hdc);
	}

}
void Actor::Update()
{
	for (Component* component : _components)
	{
		component->Update();
	}
}
void Actor::Release()
{
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}
	_components.clear();
}
void Actor::AddComponent(Component* component)
{
	if (component == nullptr)
	{
		return;
	}
	component->SetOwner(this);
	component->Init();
	_components.push_back(component);
}
void Actor::RemoveComponent(Component* component)
{
	auto findIt = find(_components.begin(), _components.end(), component);
	if (findIt != _components.end())
	{
		_components.erase(findIt);
	}
}
void Actor::OnComponentBeginOverlap(Collider* collider,  Collider* other)
{

}
void Actor::OnComponentEndOverlap(Collider* collider,  Collider* other)
{
	
}

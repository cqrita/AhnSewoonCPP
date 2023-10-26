#include "stdafx.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"
void CollisionManager::Init()
{

}
void CollisionManager::Update()
{
	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* c1 = _colliders[i];
		for (int j = 0; j < _colliders.size(); j++)
		{
			Collider* c2 = _colliders[j];
			//on collision check
			if (c1 == nullptr || c2 == nullptr)
			{

			}
			else if (c1->GetOwner() == NULL||(unsigned long long)c1->GetOwner() == 0xdddddddddddddddd || c1->GetColliderType() >= ColliderType::None||(int)c1->GetColliderType()<0)
			{

			}
			else if (c2->GetOwner() == NULL || (unsigned long long)c2->GetOwner() == 0xdddddddddddddddd || c2->GetColliderType() >= ColliderType::None || (int)c2->GetColliderType() < 0)
			{

			}
			else if (c1->CheckCollision(c2))
			{
				if (false==c1->_collisionMap.contains(c2))
				{
					c1->GetOwner()->OnComponentBeginOverlap(c1,c2);
					c1->_collisionMap.insert(c2);
				}
			}
			else
			{
				if (c1->_collisionMap.contains(c2))
				{
					c1->GetOwner()->OnComponentEndOverlap(c1, c2);
					c1->_collisionMap.erase(c2);
				}
			}
		}
	}
}
void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}
void CollisionManager::RemoveCollider(Collider* collider)
{
	auto findIt = find(_colliders.begin(), _colliders.end(), collider);
	if (findIt != _colliders.end())
	{
		_colliders.erase(findIt);
	}
	else
	{
		cout << "err" << endl;
	}
	collider == nullptr;
}

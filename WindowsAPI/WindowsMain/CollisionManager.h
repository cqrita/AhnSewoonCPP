#pragma once
class CollisionManager
{
	DECLARE_SINGLE(CollisionManager)
public:
	void Init();
	void Update();
	void AddCollider(class Collider* collider);
	void RemoveCollider(class Collider* collider);
private:
	vector<class Collider*>_colliders;
};


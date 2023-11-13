#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType = ColliderType::None;

	bool _showDebug
#if _DEBUG
		= true;
#else
		= flase;
#endif
	CollisionLayerType _collisionlayer = CollisionLayerType::CLT_OBJECT;
	uint32 _collisionFlag = ~0;
public:
	unordered_set<Collider*> _collisionMap;
public:
	using Super = Component;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }
public:
	CollisionLayerType GetCollisionLayer() { return _collisionlayer; }
	void SetCollisionLayer(CollisionLayerType collisionlayer) {_collisionlayer = collisionlayer;}
	uint32 GetCollisionFlag() { return _collisionFlag; }
	void SetCollisionFlag(uint32 flag) { _collisionFlag = flag; }
	void ResetCollisionFlag() { _collisionFlag = 0; }
	void AddCollisionFlagLayer(CollisionLayerType layer);
	void RemoveCollisionFlagLayer(CollisionLayerType layer);

public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};


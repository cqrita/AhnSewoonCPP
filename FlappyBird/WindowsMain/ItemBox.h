#pragma once
#include "GdiSpriteActor.h"
class ItemBox : public GdiSpriteActor
{
public:
	using Super = GdiSpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void SetItemBoxInfo(ItemBoxType itemBoxType,CenterRect body);
private:
	ItemBoxType _itemBoxType;
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other) override;
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other) override;

};


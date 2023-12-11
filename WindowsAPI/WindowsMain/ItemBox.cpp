#include "stdafx.h"
#include "ItemBox.h"
void ItemBox::Init()
{
	Super::Init();
	this->SetName("ItemBox");
}
void ItemBox::Render(HDC hdc)
{
	Super::Render(hdc);
}
void ItemBox::Update()
{
	Super::Update();
}
void ItemBox::Release()
{
	Super::Release();
}

void ItemBox::SetItemBoxInfo(ItemBoxType itemBoxType, CenterRect body)
{
	_itemBoxType = itemBoxType;
	switch (_itemBoxType)
	{
	case ItemBoxType::HPItemBox:
		SetSprite(L"../Resources/Items/hp_item_box.png", body);
		break;
	case ItemBoxType::MissileItemBox:
		SetSprite(L"../Resources/Items/missile_item_box.png", body);
		break;
	case ItemBoxType::None:
		break;
	}
}

void ItemBox::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	
}
void ItemBox::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}
#include "stdafx.h"
#include "ItemBox.h"
#include "Texture.h"
#include "Sprite.h"
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

void ItemBox::SetItemBoxInfo(CenterRect body)
{
	Texture* texture=GET_SINGLE(ResourceManager)->LoadTexture("T_ItemBox", "Power Ups/Power Up.png");
	Sprite* sprite = GET_SINGLE(ResourceManager)->CreateSprite("S_ItemBox",texture);
	SetSprite(sprite);
	SetBody(body);
}


void ItemBox::OnComponentBeginOverlap(class Collider* collider, class Collider* other)
{
	
}
void ItemBox::OnComponentEndOverlap(class Collider* collider, class Collider* other)
{

}
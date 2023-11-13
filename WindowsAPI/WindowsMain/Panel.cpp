#include "stdafx.h"
#include "Panel.h"

Panel::Panel()
{
	
}

Panel::~Panel()
{

}

void Panel::Init()
{
	Super::Init();
}

void Panel::Render(HDC hdc)
{
	Super::Render(hdc);
	for (UI* child : _children)
	{
		child->Render(hdc);
	}

}

void Panel::Update()
{
	Super::Update();
	for (UI* child : _children)
	{
		if (_children.size()==0) return;
		child->Update();
	}

}

void Panel::Release()
{
	Super::Release();
	for (UI* child : _children)
	{
		child->Release();
		SAFE_DELETE(child)
	}
	_children.clear();

}

void Panel::AddChild(UI* ui)
{
	if (ui == nullptr) return;
	ui->Init();
	_children.push_back(ui);
}

bool Panel::RemoveChild(UI* ui)
{
	auto findIt = find(_children.begin(), _children.end(), ui);
	if (findIt == _children.end())
	{
		return false;
	}
	_children.erase(findIt);
	return true;
}

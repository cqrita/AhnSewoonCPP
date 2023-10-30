#pragma once
#include "Panel.h"
class TestPanel : public Panel
{
	using Super = Panel;
public:
	TestPanel();
	virtual ~TestPanel();
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void OnClick_StartButton();
};


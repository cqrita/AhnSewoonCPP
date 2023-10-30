#pragma once
#include "UI.h"
class Panel : public UI
{
protected:
	vector<UI*> _children;


	using Super = UI;
public:
	Panel();
	virtual ~Panel();
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void AddChild(UI* ui);
	bool RemoveChild(UI* ui);
};


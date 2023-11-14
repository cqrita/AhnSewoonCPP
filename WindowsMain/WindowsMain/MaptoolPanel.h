#pragma once
#include "Panel.h"
class MaptoolPanel : public Panel
{
	using Super = Panel;
public:
	MaptoolPanel();
	virtual ~MaptoolPanel();
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void OnClick_Save();
	void OnClick_Revert();
	class MapToolScene* CheckValidation();
};


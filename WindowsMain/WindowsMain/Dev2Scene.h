#pragma once
#include "Scene.h"
class Dev2Scene :public Scene
{
public:
	using Super = Scene;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

};


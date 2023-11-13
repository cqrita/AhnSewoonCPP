#pragma once
#include "Component.h"
class CameraComponent :
    public Component
{
public:
	using Super = Component;

protected:
	Vector2 cameraPos{};

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	CameraComponent();
	virtual ~CameraComponent() override;

};


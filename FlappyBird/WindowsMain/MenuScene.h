#pragma once
#include "Scene.h"
class MenuScene : public Scene
{
public:
	using Super = Scene;
public:
	class Button* _button;
	class BackgroundActor* _background;
	class SpriteActor* _title;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void ChangeScene();
};


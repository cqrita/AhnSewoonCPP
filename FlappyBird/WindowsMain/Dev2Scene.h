#pragma once
#include "Scene.h"
class Dev2Scene :public Scene
{
public:
	using Super = Scene;
public:
	class BackgroundActor* _background = nullptr;
	class Player* _player = nullptr;
	class PipeActor* _pipe = nullptr;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

};


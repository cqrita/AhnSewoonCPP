#pragma once
#include "Scene.h"
class Dev2Scene :public Scene
{
public:
	using Super = Scene;
private:
	bool _mouseFlag;
	RECT _mouseRect;
	vector<class Wall*> _walls;
	vector<RECT> _rectWalls;
	int _cWall;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	void ResetButton();
	void SaveButton();
};


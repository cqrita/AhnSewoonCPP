#pragma once
#include "Scene.h"
enum class MapToolState
{
	IDLE,
	WALL_MAKE,

};
class MapToolScene : public Scene
{
public:
	using Super = Scene;
private:
	vector<RECT> _wallVec{};
	MapToolState _state=MapToolState::IDLE;
	RECT _currentRect;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	void UpdateInput();
	void UpdateIdle();
	void UpdateWallMake();
private:
	void RenderIdle(HDC hdc);
	void RenderWallMake(HDC hdc);
public:
	void Revert();
	void Save();
};


#pragma once
class UI
{
protected:
	Vector2 _pos = {};
	Vector2Int _size = {};
public:
	UI();
	virtual ~UI();
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	CenterRect GetRect();
	void SetRect(CenterRect Rect);
	bool IsInMouse();
};


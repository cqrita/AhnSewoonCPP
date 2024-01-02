#pragma once
class UI
{
protected:
	CenterRect _body;
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


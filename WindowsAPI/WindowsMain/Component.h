#pragma once
class Component
{
protected:
	class Actor* _owner=nullptr;
public:
	void SetOwner(class Actor* owner) { _owner = owner; }
	class Actor* GetOwner() { return _owner; }
public:
	virtual void Init() {}
	virtual void Render(HDC hdc) {}
	virtual void Update() {}
	virtual void Release() {}
public:
	Component() {}
	virtual ~Component() {}
};


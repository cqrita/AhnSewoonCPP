#pragma once
#include "UI.h"
enum class eButtonState
{
	Default,
	Hover,
	Pressed,
	Disabled,
	End
};
class Button : public UI
{
	using Super = UI;
protected:
	class Sprite* _currentSprite = nullptr;
	class Sprite* _sprites[static_cast<int>(eButtonState::End)] {};
	eButtonState _state = eButtonState::Default;
	function<void()> _onClick=nullptr;
public:
	void SetSprite(eButtonState state, class Sprite* sprite)
	{
		_sprites[static_cast<int>(state)] = sprite;
	}
	class Sprite* GetSprite(eButtonState state) { return _sprites[static_cast<int>(state)]; }
protected:
	void SetState(eButtonState state);
public:
	Button();
	virtual ~Button();
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	template<typename T>
	void AddOnClickDelegate( T* owner, void(T::* func)());
};

template<typename T>
inline void Button::AddOnClickDelegate(T* owner, void(T::* func)())
{
	_onClick = bind(func, owner);
}

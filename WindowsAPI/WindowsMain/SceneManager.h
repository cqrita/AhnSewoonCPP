#pragma once
//header, forward declaration
class SceneManager
{
	DECLARE_SINGLE(SceneManager)
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
	void ChangeScene();
private:
	class Scene* _scene= nullptr;
};


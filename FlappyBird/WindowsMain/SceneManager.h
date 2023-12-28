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
public:
	void ChangeScene(SceneType sceneType);
	class Scene* GetCurrentScene() { return _scene; }
private:
	class Scene* _scene= nullptr;
	SceneType _sceneType = SceneType::None;
};


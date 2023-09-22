#include <iostream>
using namespace std;
// abstract funcion

class Scene
{
public:
	virtual void Render() { cout << "Scene::Render()" << endl; };
public:
	Scene() { cout << "Scene()" << endl; }
	virtual ~Scene() { cout << "~Scene()" << endl; }

};
class LobbyScene :public Scene
{
public:
	virtual void Render() override { cout << "LobbyScene::Render()" << endl; };

public:
	LobbyScene() { cout << "LobbyScene()" << endl; }
	virtual ~LobbyScene() { cout << "~LobbyScene()" << endl; }

};
class InGameScene :public Scene
{
public:
	virtual void Render() override { cout << "InGameScene::Render()" << endl; };

public:
	InGameScene() { cout << "InGameScene()" << endl; }
	virtual ~InGameScene() { cout << "~InGameScene()" << endl; }

};

void main()
{
	Scene* scene = new LobbyScene();
	scene->Render();
	delete scene;
}
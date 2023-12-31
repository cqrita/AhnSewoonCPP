#pragma once
class Actor
{
protected:
	vector<class Component*> _components;
	CenterRect _body = {};
	string _name;
	float _rotationRadian;
	LayerType _layer = LayerType::Object;
public:
	virtual void OnComponentBeginOverlap(class Collider* collider, class Collider* other);
	virtual void OnComponentEndOverlap(class Collider* collider, class Collider* other);

public:
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }
	string GetName() { return _name; }
	void SetName(string name) { _name=name; }

	int GetLayer() { return static_cast<int>(_layer); }
	void SetLayer(LayerType layer) { _layer = layer; }

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

};


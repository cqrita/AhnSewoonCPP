#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager)

	void Init();
	void Release();
	void Update();

	int GetFps() { return _fps; }
	float GetDeltaTime() { return _deltaTime; }
private:
	unsigned long long _frequency = 0;
	unsigned long long _prevCount = 0;
	unsigned int _frameCount = 0;
private:
	int _fps = 0;
	float _deltaTime = 0;
	float _frameTime = 0;
};



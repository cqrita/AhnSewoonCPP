#include "stdafx.h"
#include "TimeManager.h"
void TimeManager::Init()
{
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}
void TimeManager::Release()
{

}
void TimeManager::Update()
{
	//GetTickCount64
	unsigned long long currentCount;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	//fps
	_frameTime += _deltaTime;
	_frameCount++;
	if (_frameTime >= 1.0f)
	{
		_fps = static_cast<unsigned int>(_frameCount / _frameTime);

		_frameTime = 0.0f;
		_frameCount = 0;
	}
}

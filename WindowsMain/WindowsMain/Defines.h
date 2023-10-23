#pragma once
#define DECLARE_SINGLE(ClassName)   \
private:                            \
	ClassName() {};                 \
	~ClassName() {};                \
public:                             \
	static ClassName* GetInstance() \
	{                               \
		static ClassName _instance; \
		return &_instance;          \
	}


#define GET_SINGLE(ClassName) ClassName::GetInstance()

#define DeltaTime GET_SINGLE(TimeManager)->GetDeltaTime()

#define EPSILON 1e-6f
#define PI 3.14159265358979
#define Deg2Rad(deg) (0.0174533*deg)
#define Rad2Deg(rad) (57.2958*rad)
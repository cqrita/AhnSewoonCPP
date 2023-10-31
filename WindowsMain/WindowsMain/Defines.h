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
#define CurrentScene GET_SINGLE(SceneManager)->GetCurrentScene()
#define Input GET_SINGLE(KeyManager)

#define EPSILON 1e-6f
#define PI 3.14159265358979f
#define Deg2Rad(deg) (0.0174533*deg)
#define Rad2Deg(rad) (57.2958*rad)

#define Alert(title,message) MessageBox(_hwnd, title, message, NULL);

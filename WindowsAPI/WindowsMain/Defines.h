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
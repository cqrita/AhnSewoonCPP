#pragma once
// precompiled header
#include <Windows.h>
#include <windowsx.h>
//c++
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 


//stl
#include <string>
#include <vector>
#include <algorithm>
#include <format>

//header
#include "Defines.h"
#include "Types.h"
#include "Enums.h"
#include "CommonFunction.h"
#include "CommonStruct.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
//namespace
using namespace std;

//define

#define WIN_NAME "SBS_ACADEMY"
#define WIN_START_X 500
#define WIN_START_Y 100
#define WIN_SIZE_WIDTH 800
#define WIN_SIZE_HEIGHT 800
#define WIN_STYLE WS_OVERLAPPEDWINDOW

#define SAFE_DELETE(p) {if((p)) delete p; (p)=NULL;}
#define SAFE_DELETE_ARRAY(p) {if((p)) delete[] p; (p)=NULL;}

extern HINSTANCE _hInstance;
extern HWND _hwnd;
extern POINT _mousePos;


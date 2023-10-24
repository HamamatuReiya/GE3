#pragma once
#include <Windows.h>

// WindowsAPI
class WinApp
{
public:
	// ウィンドウプロシージャ
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//初期化
	void Initialize();
	//更新
	void Update();

};


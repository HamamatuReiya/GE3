#pragma once
#include <Windows.h>

// WindowsAPI
class WinApp
{
public:
	// �E�B���h�E�v���V�[�W��
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//������
	void Initialize();
	//�X�V
	void Update();

};


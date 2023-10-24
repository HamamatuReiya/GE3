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

	//Getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }

	// �E�B���h�E�T�C�Y
	static const int window_width = 1280;  // ����
	static const int window_height = 720;  // �c��

private:
	HWND hwnd;
	WNDCLASSEX w{};
};


#pragma once
#include "DirectXCommon.h"

class ImGuiManager
{
public:
	// 初期化
	static void Initialize(HWND hwnd, DirectXCommon* dxCommon);

	// 更新処理
	static void NewFrame();

	// 更新終了
	static void CreateCommand();

	// コマンドを読む
	static void CommandsExcute(ID3D12GraphicsCommandList* commandList);

	//　new生成
	static ImGuiManager* Create();

public:
	//デストラクタ
	~ImGuiManager();

public:
	void ShowDemo();
};


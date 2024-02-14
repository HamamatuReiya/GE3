#pragma once
#include "DirectXCommon.h"
#include <d3d12.h>
#include <wrl.h>

#include <DirectXMath.h>

#include "SpriteCommon.h"

//単体
class Sprite
{
private:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

private:
	struct Transform{
		DirectX::XMFLOAT3 scale;
		DirectX::XMFLOAT3 rotate;
		DirectX::XMFLOAT3 translate;
	};

	// 頂点情報
	struct VertexData{
		DirectX::XMFLOAT4 position;
		DirectX::XMFLOAT2 texcoord;
	};

	// マテリアル
	struct MaterialData {
		DirectX::XMFLOAT4 color;
		DirectX::XMMATRIX uvTransform;
	};

public:
	void Initialize(SpriteCommon* common);
	void Update();
	void Draw();

private:
	// 頂点情報作成
	void CreateVertex();
	// インデックス情報作成
	void CreateIndex();
	// マテリアル情報作成
	void CreateMaterial();
	// 行列情報作成
	void CreateWVP();

private:
	DirectXCommon* dxCommon_ = nullptr;
	SpriteCommon* common_ = nullptr;

	// 頂点情報
	ComPtr<ID3D12Resource> vertexResource;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};

	// インデックス
	ComPtr<ID3D12Resource> indexResource;
	D3D12_INDEX_BUFFER_VIEW indexBufferView{};

	// マテリアル情報
	ComPtr<ID3D12Resource> materialResource;
	MaterialData* materialData = nullptr;

	// 行列情報
	ComPtr<ID3D12Resource> wvpResource;
	DirectX::XMMATRIX* wvpData = nullptr;

	// 画像の保存先アドレス
	D3D12_GPU_DESCRIPTOR_HANDLE textureSrvHandleGPU;

	// パラメーター
	DirectX::XMFLOAT4 color_{ 1.0f,1.0f,1.0f,1.0f };
	// UV座標
	Transform uvTransform = { {1,1,1},{0,0,0},{0,0,0} };

	//自機                   Scale   Rotate Translate
	Transform transform = { {1,1,1},{0,0,0},{0,0,0} };

	// カメラ
	Transform cameraTransform = { {1,1,1},{0,0,0},{0,0,-5} };
};


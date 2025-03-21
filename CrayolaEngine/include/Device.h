#pragma once
#include "Prerequisites.h"

class
Device {
public:
	/* Constructor por defecto. */

	Device() = default;

	/* Destructor por defecto. */
	~Device() = default;

	/*
	 * @brief Inicializa el dispositivo.
	 */
	void
	init();

	/*
	 * @brief Actualiza el estado del dispositivo.
	 */
	void
	update();

	/*
	 * @brief Ejecuta operaciones de renderizado relacionadas con el dispositivo.
	 */
	void
	render();

	/**
	 * @brief Libera los recursos del dispositivo.
	 */
	void
	destroy();

	/**
	 * @brief Crea una Render Target View.
	 */
	HRESULT
	CreateRenderTargetView(ID3D11Resource* pResource,
			const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
			ID3D11RenderTargetView** ppRTView);

	/**
	 * @brief Crea una textura 2D.
	 */
	HRESULT
	CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
			const D3D11_SUBRESOURCE_DATA* pInitialData,
			ID3D11Texture2D** ppTexture2D);

	/*
	 * @brief Crea una Depth Stencil View.
	 */

	HRESULT
	CreateDepthStencilView(ID3D11Resource* pResource,
			const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
			ID3D11DepthStencilView** ppDepthStencilView);

	/*
	 * @brief Crea un Vertex Shader.
	 */
	HRESULT
	CreateVertexShader(const void* pShaderBytecode,
			unsigned int BytecodeLength,
			ID3D11ClassLinkage* pClassLinkage,
			ID3D11VertexShader** ppVertexShader);

	/*
	 * @brief Crea un Input Layout para los datos del Vertex Shader.
	 */
	HRESULT
	CreateInputLayout(D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
			unsigned int NumElements,
			const void* pShaderBytecodeWithInputSignature,
			unsigned int BytecodeLength,
			ID3D11InputLayout** ppInputLayout);

	/*
	 * @brief Crea un Pixel Shader.
	 */
	HRESULT
	CreatePixelShader(const void* pShaderBytecode,
			unsigned int BytecodeLength,
			ID3D11ClassLinkage* pClassLinkage,
			ID3D11PixelShader** ppPixelShader);

	/*
	 * @brief Crea un Buffer (vertex, index o constante).
	 */
	HRESULT
	CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
			const D3D11_SUBRESOURCE_DATA* pInitialData,
			ID3D11Buffer** ppBuffer);

	/*
	 * @brief Crea un Sampler State.
	 */
	HRESULT
	CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
			ID3D11SamplerState** ppSamplerState);

	/*
	 * @brief Crea un Rasterizer State.
	 */
	HRESULT
	CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc,
			ID3D11RasterizerState** ppRasterizerState);

	/*
	 * @brief Crea un Blend State.
	 */
	HRESULT
	CreateBlendState(const D3D11_BLEND_DESC* pBlendStateDesc,
			ID3D11BlendState** ppBlendState);

public:
	ID3D11Device* m_device = nullptr;
};
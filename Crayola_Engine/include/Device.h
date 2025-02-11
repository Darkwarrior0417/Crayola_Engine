#pragma once
#include "Prerequisites.h"
class
	Device {
public:
	Device() = default;
	~Device() = default;

	/**
	 * @brief Inicializa el dispositivo.
	 */
	void
		init();

	/**
	 * @brief Actualiza el estado del dispositivo.
	 */
	void
		update();

	/**
	 * @brief Renderiza el contenido utilizando el dispositivo.
	 */
	void
		render();

	/**
	 * @brief Destruye el dispositivo y libera los recursos asociados.
	 */
	void
		destroy();

	/**
	* @brief Crea el render target view.
	* @param pResource Recurso.
	* @param pDesc Descripci�n del render target view.
	* @param ppRTView Puntero al render target view.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateRenderTargetView(ID3D11Resource* pResource,
			const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
			ID3D11RenderTargetView** ppRTView);

	/**
	* @brief Crea una textura 2D.
	* @param pDesc Descripci�n de la textura.
	* @param pInitialData Datos iniciales.
	* @param ppTexture2D Puntero a la textura.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
			const D3D11_SUBRESOURCE_DATA* pInitialData,
			ID3D11Texture2D** ppTexture2D);

	/**
	* @brief Crea la vista de profundidad y stencil.
	* @param pResource Recurso.
	* @param pDesc Descripci�n de la vista de profundidad y stencil.
	* @param ppDepthStencilView Puntero a la vista de profundidad y stencil.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateDepthStencilView(ID3D11Resource* pResource,
			const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
			ID3D11DepthStencilView** ppDepthStencilView);

	/**
	* @brief Crea el sombreador de v�rtices.
	* @param pShaderBytecode C�digo de sombreador.
	* @param BytecodeLength Longitud del c�digo de sombreador.
	* @param pClassLinkage Vinculaci�n de clases.
	* @param ppVertexShader Puntero al sombreador de v�rtices.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateVertexShader(const void* pShaderBytecode,
			unsigned int BytecodeLength,
			ID3D11ClassLinkage* pClassLinkage,
			ID3D11VertexShader** ppVertexShader);

	/**
	* @brief Crea el input layout.
	* @param pInputElementDescs Descripci�n de los elementos de entrada.
	* @param NumElements N�mero de elementos.
	* @param pShaderBytecodeWithInputSignature C�digo de sombreador con firma de entrada.
	* @param BytecodeLength Longitud del c�digo de sombreador.
	* @param ppInputLayout Puntero al input layout.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateInputLayout(D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
			unsigned int NumElements,
			const void* pShaderBytecodeWithInputSignature,
			unsigned int BytecodeLength,
			ID3D11InputLayout** ppInputLayout);

	/**
	* @brief Crea el sombreador de p�xeles.
	* @param pShaderBytecode C�digo de sombreador.
	* @param BytecodeLength Longitud del c�digo de sombreador.
	* @param pClassLinkage Vinculaci�n de clases.
	* @param ppPixelShader Puntero al sombreador de p�xeles.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreatePixelShader(const void* pShaderBytecode,
			unsigned int BytecodeLength,
			ID3D11ClassLinkage* pClassLinkage,
			ID3D11PixelShader** ppPixelShader);

	/**
	* @brief Crea el buffer.
	* @param pDesc Descripci�n del buffer.
	* @param pInitialData Datos iniciales.
	* @param ppBuffer Puntero al buffer.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
			const D3D11_SUBRESOURCE_DATA* pInitialData,
			ID3D11Buffer** ppBuffer);

	/**
	* @brief Crea el sampler state.
	* @param pSamplerDesc Descripci�n del sampler state.
	* @param ppSamplerState Puntero al sampler state.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
			ID3D11SamplerState** ppSamplerState);

	/**
	* @brief Crea el rasterizer state.
	* @param pRasterizerDesc Descripci�n del rasterizer state.
	* @param ppRasterizerState Puntero al rasterizer state.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc,
			ID3D11RasterizerState** ppRasterizerState);

	/**
	* @brief Crea el depth stencil state.
	* @param pDepthStencilDesc Descripci�n del depth stencil state.
	* @param ppDepthStencilState Puntero al depth stencil state.
	* @return HRESULT Indica el �xito o fallo de la operaci�n.
	*/
	HRESULT
		CreateBlendState(const D3D11_BLEND_DESC* pBlendStateDesc,
			ID3D11BlendState** ppBlendState);
public:
	ID3D11Device* m_device = nullptr; ///< Dispositivo.
};
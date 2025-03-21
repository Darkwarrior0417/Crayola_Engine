#pragma once
#include "PreRequisites.h"

class
DeviceContext {
public:
	DeviceContext() = default;
	~DeviceContext() = default;

	/* @brief Inicializa el contexto del dispositivo. */
	void
	init();

	/* @brief Actualiza estados o recursos dentro del contexto. */
	void
	update();

	/* @brief Ejecuta el renderizado desde el contexto. */
	void
	render();

	/* @brief Libera los recursos asociados al contexto. */
	void
	destroy();

	/* @brief Establece los viewports activos. */
	void
	RSSetViewports(unsigned int NumViewports, const D3D11_VIEWPORT* pViewports);

	/* @brief Asigna recursos de textura al pixel shader. */
	void
	PSSetShaderResources(unsigned int StartSlot,
			unsigned int NumViews,
			ID3D11ShaderResourceView* const* ppShaderResourceViews);

	/* @brief Establece el layout de entrada para la etapa de ensamblaje. */
	void
	IASetInputLayout(ID3D11InputLayout* pInputLayout);

	/* @brief Establece el vertex shader actual. */
	void
	VSSetShader(ID3D11VertexShader* pVertexShader,
			ID3D11ClassInstance* const* ppClassInstances,
			unsigned int NumClassInstances);
	/* @brief Establece el pixel shader actual. */
	void
	PSSetShader(ID3D11PixelShader* pPixelShader,
			ID3D11ClassInstance* const* ppClassInstances,
			unsigned int NumClassInstances);
	/* @brief Actualiza los datos de un recurso (como un buffer constante). */
	void
	UpdateSubresource(ID3D11Resource* pDstResource,
			unsigned int DstSubresource,
			const D3D11_BOX* pDstBox,
			const void* pSrcData,
			unsigned int SrcRowPitch,
			unsigned int SrcDepthPitch);

	/* @brief Asigna los vertex buffers al pipeline. */
	void
	IASetVertexBuffers(unsigned int StartSlot,
			unsigned int NumBuffers,
			ID3D11Buffer* const* ppVertexBuffers,
			const unsigned int* pStrides,
			const unsigned int* pOffsets);
	/* @brief Asigna el index buffer al pipeline. */
	void
	IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
			DXGI_FORMAT Format,
			unsigned int Offset);

	/* @brief Asigna los samplers al pixel shader. */
	void
	PSSetSamplers(unsigned int StartSlot,
			unsigned int NumSamplers,
			ID3D11SamplerState* const* ppSamplers);

	/* @brief Establece el estado del rasterizador. */
	void
	RSSetState(ID3D11RasterizerState* pRasterizerState);

	/* @brief Define el estado de mezcla para el render target. */
	void
	OMSetBlendState(ID3D11BlendState* pBlendState,
			const float BlendFactor[4],
			unsigned int SampleMask);

	/* @brief Establece los render targets y el depth stencil view. */
	void
	OMSetRenderTargets(unsigned int NumViews,
			ID3D11RenderTargetView* const* ppRenderTargetViews,
			ID3D11DepthStencilView* pDepthStencilView);

	/* @brief Define la topología de primitivas (triángulos, líneas, etc). */
	void
	IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

	/* @brief Limpia el render target con un color. */
	void
	ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
			const float ColorRGBA[4]);

	/* @brief Limpia el depth stencil view. */
	void
	ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
			unsigned int ClearFlags,
			float Depth,
			UINT8 Stencil);

	/* @brief Asigna buffers constantes al vertex shader. */
	void
	VSSetConstantBuffers(unsigned int StartSlot,
			unsigned int NumBuffers,
			ID3D11Buffer* const* ppConstantBuffers);

	/* @brief Asigna buffers constantes al pixel shader. */
	void
	PSSetConstantBuffers(unsigned int StartSlot,
			unsigned int NumBuffers,
			ID3D11Buffer* const* ppConstantBuffers);

	/* @brief Ejecuta un draw con índice (usando el index buffer). */
	void
	DrawIndexed(unsigned int IndexCount,
			unsigned int StartIndexLocation,
			int BaseVertexLocation);
private:

public:
	ID3D11DeviceContext* m_deviceContext = nullptr;
};
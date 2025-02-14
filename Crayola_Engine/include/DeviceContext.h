#pragma once
#include "PreRequisites.h"

/**
 * @class DeviceContext
 * @brief Clase que gestiona el contexto del dispositivo Direct3D 11.
 *
 * Proporciona m�todos para configurar y ejecutar operaciones de renderizado
 * en el pipeline gr�fico de Direct3D.
 */
class
    DeviceContext {
public:
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    DeviceContext() = default;
    ~DeviceContext() = default;

    void
        init();

    void
        update();

    void
        render();

    void
        destroy();

    void
        OMSetRenderTargets(unsigned int NumViews,
            ID3D11RenderTargetView* const* ppRenderTargetViews,
            ID3D11DepthStencilView* pDepthStencilView);

=======
    /**
     * @brief Constructor por defecto.
     */
    DeviceContext() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~DeviceContext() = default;

    /**
     * @brief Inicializa el contexto del dispositivo.
     */
    void
        init();

    /**
     * @brief Actualiza los estados del contexto del dispositivo.
     */
    void
        update();

    /**
     * @brief Realiza operaciones de renderizado utilizando el contexto del dispositivo.
     */
    void
        render();

    /**
     * @brief Libera los recursos del contexto del dispositivo.
     */
    void
        destroy();

    /**
     * @brief Establece las vistas de la pantalla.
     *
     * @param NumViewports N�mero de viewports a establecer.
     * @param pViewports Puntero a los viewports.
     */
>>>>>>> Stashed changes
    void
        RSSetViewports(unsigned int NumViewports,
            const D3D11_VIEWPORT* pViewports);

<<<<<<< Updated upstream
    void
        IASetInputLayout(ID3D11InputLayout* pInputLayout);

    void
        IASetVertexBuffers(unsigned int StartSlot,
            unsigned int NumBuffers,
            ID3D11Buffer* const* ppVertexBuffers,
            const unsigned int* pStrides,
            const unsigned int* pOffsets);

    void
        IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
            DXGI_FORMAT Format,
            unsigned int Offset);

    void
        IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

=======
    /**
     * @brief Asigna recursos de textura a la etapa de p�xeles del pipeline.
     *
     * @param StartSlot Primer slot en el que se asignar� el recurso.
     * @param NumViews N�mero de vistas a asignar.
     * @param ppShaderResourceViews Puntero a la lista de vistas de recursos de shader.
     */
    void
        PSSetShaderResources(unsigned int StartSlot,
            unsigned int NumViews,
            ID3D11ShaderResourceView* const* ppShaderResourceViews);

    /**
     * @brief Establece el dise�o de entrada para la etapa de entrada del ensamblador.
     *
     * @param pInputLayout Puntero al dise�o de entrada.
     */
    void
        IASetInputLayout(ID3D11InputLayout* pInputLayout);

    /**
     * @brief Establece el shader de v�rtices en el pipeline.
     *
     * @param pVertexShader Puntero al shader de v�rtices.
     * @param ppClassInstances Lista de instancias de clase.
     * @param NumClassInstances N�mero de instancias de clase.
     */
    void
        VSSetShader(ID3D11VertexShader* pVertexShader,
            ID3D11ClassInstance* const* ppClassInstances,
            unsigned int NumClassInstances);

    /**
     * @brief Establece el shader de p�xeles en el pipeline.
     *
     * @param pPixelShader Puntero al shader de p�xeles.
     * @param ppClassInstances Lista de instancias de clase.
     * @param NumClassInstances N�mero de instancias de clase.
     */
    void
        PSSetShader(ID3D11PixelShader* pPixelShader,
            ID3D11ClassInstance* const* ppClassInstances,
            unsigned int NumClassInstances);

    /**
     * @brief Actualiza los datos de un recurso en la GPU.
     *
     * @param pDstResource Recurso de destino.
     * @param DstSubresource Subrecurso de destino.
     * @param pDstBox Regi�n de destino a actualizar (opcional).
     * @param pSrcData Datos de origen.
     * @param SrcRowPitch Desplazamiento por fila.
     * @param SrcDepthPitch Desplazamiento por profundidad.
     */
>>>>>>> Stashed changes
    void
        UpdateSubresource(ID3D11Resource* pDstResource,
            unsigned int DstSubresource,
            const D3D11_BOX* pDstBox,
            const void* pSrcData,
            unsigned int SrcRowPitch,
            unsigned int SrcDepthPitch);

<<<<<<< Updated upstream
    void
        ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
            const FLOAT ColorRGBA[4]);

    void
        ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
            FLOAT Depth,
            UINT8 Stencil);

    void
        VSSetShader(ID3D11VertexShader* pVertexShader,
            ID3D11ClassInstance* const* ppClassInstances,
            unsigned int NumClassInstances);

=======
    /**
     * @brief Constructor por defecto.
     */
    DeviceContext() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~DeviceContext() = default;

    /**
     * @brief Inicializa el contexto del dispositivo.
     */
    void
        init();

    /**
     * @brief Actualiza los estados del contexto del dispositivo.
     */
    void
        update();

    /**
     * @brief Realiza operaciones de renderizado utilizando el contexto del dispositivo.
     */
    void
        render();

    /**
     * @brief Libera los recursos del contexto del dispositivo.
     */
    void
        destroy();

    /**
     * @brief Establece las vistas de la pantalla.
     *
     * @param NumViewports N�mero de viewports a establecer.
     * @param pViewports Puntero a los viewports.
     */
    void
        RSSetViewports(unsigned int NumViewports,
            const D3D11_VIEWPORT* pViewports);

    /**
     * @brief Asigna recursos de textura a la etapa de p�xeles del pipeline.
     *
     * @param StartSlot Primer slot en el que se asignar� el recurso.
     * @param NumViews N�mero de vistas a asignar.
     * @param ppShaderResourceViews Puntero a la lista de vistas de recursos de shader.
     */
    void
        PSSetShaderResources(unsigned int StartSlot,
            unsigned int NumViews,
            ID3D11ShaderResourceView* const* ppShaderResourceViews);

    /**
     * @brief Establece el dise�o de entrada para la etapa de entrada del ensamblador.
     *
     * @param pInputLayout Puntero al dise�o de entrada.
     */
    void
        IASetInputLayout(ID3D11InputLayout* pInputLayout);

    /**
     * @brief Establece el shader de v�rtices en el pipeline.
     *
     * @param pVertexShader Puntero al shader de v�rtices.
     * @param ppClassInstances Lista de instancias de clase.
     * @param NumClassInstances N�mero de instancias de clase.
     */
    void
        VSSetShader(ID3D11VertexShader* pVertexShader,
            ID3D11ClassInstance* const* ppClassInstances,
            unsigned int NumClassInstances);

    /**
     * @brief Establece el shader de p�xeles en el pipeline.
     *
     * @param pPixelShader Puntero al shader de p�xeles.
     * @param ppClassInstances Lista de instancias de clase.
     * @param NumClassInstances N�mero de instancias de clase.
     */
    void
        PSSetShader(ID3D11PixelShader* pPixelShader,
            ID3D11ClassInstance* const* ppClassInstances,
            unsigned int NumClassInstances);

    /**
     * @brief Actualiza los datos de un recurso en la GPU.
     *
     * @param pDstResource Recurso de destino.
     * @param DstSubresource Subrecurso de destino.
     * @param pDstBox Regi�n de destino a actualizar (opcional).
     * @param pSrcData Datos de origen.
     * @param SrcRowPitch Desplazamiento por fila.
     * @param SrcDepthPitch Desplazamiento por profundidad.
     */
    void
        UpdateSubresource(ID3D11Resource* pDstResource,
            unsigned int DstSubresource,
            const D3D11_BOX* pDstBox,
            const void* pSrcData,
            unsigned int SrcRowPitch,
            unsigned int SrcDepthPitch);

    /**
     * @brief Asigna buffers de v�rtices al pipeline gr�fico.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers N�mero de buffers.
     * @param ppVertexBuffers Puntero a los buffers de v�rtices.
     * @param pStrides Tama�o de cada v�rtice en los buffers.
     * @param pOffsets Desplazamiento inicial en los buffers.
     */
    void
        IASetVertexBuffers(unsigned int StartSlot,
            unsigned int NumBuffers,
            ID3D11Buffer* const* ppVertexBuffers,
            const unsigned int* pStrides,
            const unsigned int* pOffsets);

    /**
     * @brief Asigna un buffer de �ndices al pipeline gr�fico.
     *
     * @param pIndexBuffer Puntero al buffer de �ndices.
     * @param Format Formato de los �ndices.
     * @param Offset Desplazamiento dentro del buffer.
     */
    void
        IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
            DXGI_FORMAT Format,
            unsigned int Offset);

    /**
     * @brief Establece los estados de muestreo en la etapa de p�xeles.
     *
     * @param StartSlot Primer slot del sampler.
     * @param NumSamplers N�mero de estados de muestreo.
     * @param ppSamplers Puntero a los estados de muestreo.
     */
    void
        PSSetSamplers(unsigned int StartSlot,
            unsigned int NumSamplers,
            ID3D11SamplerState* const* ppSamplers);

    /**
     * @brief Configura el estado de rasterizaci�n.
     *
     * @param pRasterizerState Puntero al estado de rasterizaci�n.
     */
    void
        RSSetState(ID3D11RasterizerState* pRasterizerState);

    /**
     * @brief Configura el estado de mezcla para la etapa de salida.
     *
     * @param pBlendState Puntero al estado de mezcla.
     * @param BlendFactor Factores de mezcla de color.
     * @param SampleMask M�scara de muestreo.
     */
    void
        OMSetBlendState(ID3D11BlendState* pBlendState,
            const float BlendFactor[4],
            unsigned int SampleMask);

    /**
     * @brief Establece los objetivos de renderizado y el buffer de profundidad.
     *
     * @param NumViews N�mero de vistas de renderizado.
     * @param ppRenderTargetViews Puntero a la lista de vistas de renderizado.
     * @param pDepthStencilView Puntero a la vista de profundidad y stencil.
     */
    void
        OMSetRenderTargets(unsigned int NumViews,
            ID3D11RenderTargetView* const* ppRenderTargetViews,
            ID3D11DepthStencilView* pDepthStencilView);

    /**
     * @brief Establece la topolog�a primitiva utilizada en el pipeline.
     *
     * @param Topology Tipo de topolog�a de primitivas.
     */
    void
        IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

    /**
     * @brief Limpia una vista de renderizado con un color espec�fico.
     *
     * @param pRenderTargetView Puntero a la vista de renderizado.
     * @param ColorRGBA Color en formato RGBA.
     */
    void
        ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
            const float ColorRGBA[4]);

    /**
     * @brief Limpia el buffer de profundidad y stencil.
     *
     * @param pDepthStencilView Puntero a la vista de profundidad y stencil.
     * @param ClearFlags Flags que indican qu� limpiar (profundidad/stencil).
     * @param Depth Valor de profundidad a establecer.
     * @param Stencil Valor de stencil a establecer.
     */
    void
        ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
            unsigned int ClearFlags,
            float Depth,
            UINT8 Stencil);

    /**
     * @brief Asigna buffers constantes a la etapa de v�rtices.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers N�mero de buffers.
     * @param ppConstantBuffers Puntero a los buffers constantes.
     */
>>>>>>> Stashed changes
    void
        VSSetConstantBuffers(unsigned int StartSlot,
            unsigned int NumBuffers,
            ID3D11Buffer* const* ppConstantBuffers);

<<<<<<< Updated upstream
    void
        PSSetShader(ID3D11PixelShader* pPixelShader,
            ID3D11ClassInstance* const* ppClassInstances,
            unsigned int NumClassInstances);

=======
    /**
     * @brief Asigna buffers constantes a la etapa de p�xeles.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers N�mero de buffers.
     * @param ppConstantBuffers Puntero a los buffers constantes.
     */
>>>>>>> Stashed changes
    void
        PSSetConstantBuffers(unsigned int StartSlot,
            unsigned int NumBuffers,
            ID3D11Buffer* const* ppConstantBuffers);

<<<<<<< Updated upstream
    void
        PSSetShaderResources(unsigned int StartSlot,
            unsigned int NumViews,
            ID3D11ShaderResourceView* const* ppShaderResourceViews);

    void
        PSSetSamplers(unsigned int StartSlot,
            unsigned int NumSamplers,
            ID3D11SamplerState* const* ppSamplers);

    void
        DrawIndexed(unsigned int IndexCount,
            unsigned int StartIndexLocation,
            INT BaseVertexLocation);

public:
    ID3D11DeviceContext* m_deviceContext = nullptr;

private:

=======
    /**
     * @brief Asigna buffers de v�rtices al pipeline gr�fico.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers N�mero de buffers.
     * @param ppVertexBuffers Puntero a los buffers de v�rtices.
     * @param pStrides Tama�o de cada v�rtice en los buffers.
     * @param pOffsets Desplazamiento inicial en los buffers.
     */
    void
        IASetVertexBuffers(unsigned int StartSlot,
            unsigned int NumBuffers,
            ID3D11Buffer* const* ppVertexBuffers,
            const unsigned int* pStrides,
            const unsigned int* pOffsets);

    /**
     * @brief Asigna un buffer de �ndices al pipeline gr�fico.
     *
     * @param pIndexBuffer Puntero al buffer de �ndices.
     * @param Format Formato de los �ndices.
     * @param Offset Desplazamiento dentro del buffer.
     */
    void
        IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
            DXGI_FORMAT Format,
            unsigned int Offset);

    /**
     * @brief Establece los estados de muestreo en la etapa de p�xeles.
     *
     * @param StartSlot Primer slot del sampler.
     * @param NumSamplers N�mero de estados de muestreo.
     * @param ppSamplers Puntero a los estados de muestreo.
     */
    void
        PSSetSamplers(unsigned int StartSlot,
            unsigned int NumSamplers,
            ID3D11SamplerState* const* ppSamplers);

    /**
     * @brief Configura el estado de rasterizaci�n.
     *
     * @param pRasterizerState Puntero al estado de rasterizaci�n.
     */
    void
        RSSetState(ID3D11RasterizerState* pRasterizerState);

    /**
     * @brief Configura el estado de mezcla para la etapa de salida.
     *
     * @param pBlendState Puntero al estado de mezcla.
     * @param BlendFactor Factores de mezcla de color.
     * @param SampleMask M�scara de muestreo.
     */
    void
        OMSetBlendState(ID3D11BlendState* pBlendState,
            const float BlendFactor[4],
            unsigned int SampleMask);

    /**
     * @brief Establece los objetivos de renderizado y el buffer de profundidad.
     *
     * @param NumViews N�mero de vistas de renderizado.
     * @param ppRenderTargetViews Puntero a la lista de vistas de renderizado.
     * @param pDepthStencilView Puntero a la vista de profundidad y stencil.
     */
    void
        OMSetRenderTargets(unsigned int NumViews,
            ID3D11RenderTargetView* const* ppRenderTargetViews,
            ID3D11DepthStencilView* pDepthStencilView);

    /**
     * @brief Establece la topolog�a primitiva utilizada en el pipeline.
     *
     * @param Topology Tipo de topolog�a de primitivas.
     */
    void
        IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

    /**
     * @brief Limpia una vista de renderizado con un color espec�fico.
     *
     * @param pRenderTargetView Puntero a la vista de renderizado.
     * @param ColorRGBA Color en formato RGBA.
     */
    void
        ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
            const float ColorRGBA[4]);

    /**
     * @brief Limpia el buffer de profundidad y stencil.
     *
     * @param pDepthStencilView Puntero a la vista de profundidad y stencil.
     * @param ClearFlags Flags que indican qu� limpiar (profundidad/stencil).
     * @param Depth Valor de profundidad a establecer.
     * @param Stencil Valor de stencil a establecer.
     */
    void
        ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
            unsigned int ClearFlags,
            float Depth,
            UINT8 Stencil);

    /**
     * @brief Asigna buffers constantes a la etapa de v�rtices.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers N�mero de buffers.
     * @param ppConstantBuffers Puntero a los buffers constantes.
     */
    void
        VSSetConstantBuffers(unsigned int StartSlot,
            unsigned int NumBuffers,
            ID3D11Buffer* const* ppConstantBuffers);

    /**
     * @brief Asigna buffers constantes a la etapa de p�xeles.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers N�mero de buffers.
     * @param ppConstantBuffers Puntero a los buffers constantes.
     */
    void
        PSSetConstantBuffers(unsigned int StartSlot,
            unsigned int NumBuffers,
            ID3D11Buffer* const* ppConstantBuffers);

    /**
     * @brief Dibuja los elementos indexados.
     *
     * @param IndexCount N�mero de �ndices.
     * @param StartIndexLocation Ubicaci�n inicial del �ndice.
     * @param BaseVertexLocation Ubicaci�n base del v�rtice.
     */
    void
        DrawIndexed(unsigned int IndexCount,
            unsigned int StartIndexLocation,
            int BaseVertexLocation);

public:
    /// Puntero al contexto del dispositivo Direct3D.
    ID3D11DeviceContext* m_deviceContext = nullptr;
>>>>>>> Stashed changes
=======
    /**
     * @brief Dibuja los elementos indexados.
     *
     * @param IndexCount N�mero de �ndices.
     * @param StartIndexLocation Ubicaci�n inicial del �ndice.
     * @param BaseVertexLocation Ubicaci�n base del v�rtice.
     */
    void
        DrawIndexed(unsigned int IndexCount,
            unsigned int StartIndexLocation,
            int BaseVertexLocation);

public:
    /// Puntero al contexto del dispositivo Direct3D.
    ID3D11DeviceContext* m_deviceContext = nullptr;
>>>>>>> Stashed changes
};
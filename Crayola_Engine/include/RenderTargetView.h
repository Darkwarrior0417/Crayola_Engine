#pragma once
#include "Prerequisites.h"

class
    Device;
class
    DeviceContext;
class
    Texture;
class
    DepthStencilView;

/**
 * @class RenderTargetView
 * @brief Clase que representa una vista de salida de renderizado en Direct3D 11.
 *
 * Se encarga de gestionar un ID3D11RenderTargetView, utilizado
 * para representar el área de renderizado en la que se dibujan los gráficos.
 */
class
    RenderTargetView {
public:
    /**
     * @brief Constructor por defecto.
     */
    RenderTargetView() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~RenderTargetView() = default;

    /**
     * @brief Inicializa la vista de salida de renderizado.
     *
     * @param device Referencia al dispositivo Direct3D usado para la creación.
     * @param backBuffer Referencia a la textura del búfer posterior.
     * @param Format Formato del render target view (DXGI_FORMAT).
     * @return HRESULT Resultado indicando si la operación fue exitosa o si ocurrió un error.
     */
    HRESULT
        init(Device& device,
            Texture& backBuffer,
            DXGI_FORMAT Format);

    /**
     * @brief Realiza las actualizaciones necesarias de la vista de salida de renderizado.
     */
    void
        update();

    /**
     * @brief Dibuja la escena usando la vista de salida de renderizado.
     *
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param depthStencilView Referencia a la vista de profundidad y stencil.
     * @param numViews Número de vistas a configurar en el pipeline de renderizado.
     * @param ClearColor Color que se utilizará para limpiar la vista de salida.
     */
    void
        render(DeviceContext& deviceContext,
            DepthStencilView& depthStencilView,
            unsigned int numViews,
            const float ClearColor[4]);

    /**
     * @brief Libera los recursos asociados con la vista de salida de renderizado.
     */
    void
        destroy();

public:
    /// Puntero a la interfaz ID3D11RenderTargetView que representa la vista de salida.
    ID3D11RenderTargetView* m_renderTargetView = nullptr;
};

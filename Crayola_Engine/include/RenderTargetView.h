#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Texture;
class DepthStencilView;

/**
 * @class RenderTargetView
 * @brief Clase que representa una vista de salida de renderizado en Direct3D 11.
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
    ID3D11RenderTargetView* m_renderTargetView = nullptr;
};

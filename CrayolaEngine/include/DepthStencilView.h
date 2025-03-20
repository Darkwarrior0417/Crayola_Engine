#pragma once
#include "PreRequisites.h"

class Device;
class DeviceContext;
class Texture;

/**
 * @class DepthStencilView
 * @brief Clase que representa una vista de profundidad y stencil en DirectX 11.
 *
 * Esta clase encapsula un ID3D11DepthStencilView, utilizado para gestionar
 * los buffers de profundidad y stencil en una aplicación de gráficos.
 */
class
DepthStencilView {
public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa una nueva instancia de la clase DepthStencilView.
     */
    DepthStencilView() = default;

    /**
     * @brief Destructor por defecto.
     *
     * Libera los recursos de la clase DepthStencilView al destruir la instancia.
     */
    ~DepthStencilView() = default;

    /**
     * @brief Inicializa la vista de profundidad y stencil.
     */
    HRESULT 
    init(Device& device,Texture& depthStencil,DXGI_FORMAT format);

    /**
     * @brief Actualiza la vista de profundidad y stencil si es necesario.
     */
    void
    update();

    /**
     * @brief Vincula la vista de profundidad y stencil al contexto del dispositivo.
     */
    void 
    render(DeviceContext& deviceContext);

    /**
     * @brief Libera los recursos asociados con la vista de profundidad y stencil.
     */
    void 
    destroy();

public:
    /// Puntero a la interfaz ID3D11DepthStencilView que representa la vista de profundidad y stencil.
    ID3D11DepthStencilView* m_depthStencilView = nullptr;
};
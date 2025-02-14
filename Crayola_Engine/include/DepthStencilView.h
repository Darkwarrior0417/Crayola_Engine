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
class DepthStencilView {
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
     *
     * Crea una vista de profundidad y stencil a partir de la textura proporcionada y el formato indicado.
     *
     * @param device Referencia al dispositivo Direct3D que creará la vista.
     * @param depthStencil Referencia a la textura que actuará como buffer de profundidad y stencil.
     * @param format Formato del buffer de profundidad y stencil (DXGI_FORMAT).
     * @return HRESULT Código de resultado que indica el éxito o error de la operación.
     */
    HRESULT init(Device& device,
        Texture& depthStencil,
        DXGI_FORMAT format);

    /**
     * @brief Actualiza la vista de profundidad y stencil si es necesario.
     *
     * Esta función se utiliza para realizar cambios dinámicos en la vista cuando sea necesario,
     * según el contexto de la aplicación.
     */
    void update();

    /**
     * @brief Vincula la vista de profundidad y stencil al contexto del dispositivo.
     *
     * @param deviceContext Referencia al contexto del dispositivo en el que se aplicará la vista.
     */
    void render(DeviceContext& deviceContext);

    /**
     * @brief Libera los recursos asociados con la vista de profundidad y stencil.
     *
     * Esta función debe llamarse antes de la destrucción de la clase para evitar pérdidas de memoria.
     */
    void destroy();

public:
    /// Puntero a la interfaz ID3D11DepthStencilView que representa la vista de profundidad y stencil.
    ID3D11DepthStencilView* m_depthStencilView = nullptr;
};
#pragma once
#include "Prerequisites.h"

class Window;
class DeviceContext;

/**
 * @brief Encapsula la configuración y manejo de un viewport en DirectX 11.
 * Define el área de la pantalla donde se renderiza la escena.
 */
class Viewport {
public:
    Viewport() = default;
    ~Viewport() = default;

    /**
     * @brief Inicializa el viewport usando las dimensiones de la ventana.
     * @param window Referencia a la ventana principal.
     * @return HRESULT que indica éxito o fallo.
     */
    HRESULT init(const Window& window);

    /**
     * @brief Inicializa el viewport directamente con valores de ancho y alto.
     * @param width Ancho del viewport.
     * @param height Alto del viewport.
     * @return HRESULT que indica éxito o fallo.
     */
    HRESULT init(unsigned int width, unsigned int height);

    /**
     * @brief Actualiza el estado del viewport (si aplica).
     */
    void update();

    /**
     * @brief Establece el viewport en el pipeline de renderizado.
     * @param deviceContext Contexto de dispositivo de DirectX.
     */
    void render(DeviceContext& deviceContext);

    /**
     * @brief Libera los recursos asociados al viewport.
     */
    void destroy();

public:
    D3D11_VIEWPORT m_viewport; /* Estructura nativa de DirectX 11 que define el área de dibujo. */
};

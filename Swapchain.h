#pragma once
#include "Prerequisites.h"

// Forward Declarations - Declaraciones Directas
class Device;
class DeviceContext;
class Window;
class Texture;


class
    Swapchain {
public:
    Swapchain() = default;
    ~Swapchain() = default;

    /**
     * @brief Inicializa el swapchain.
     *
     * @param device Dispositivo.
     * @param deviceContext Contexto del dispositivo.
     * @param backBuffer Textura de la ventana.
     * @param window Ventana.
     */
    void
        init(Device& device,
            DeviceContext& deviceContext,
            Texture& backBuffer,
            Window& window);

    /**
    * @brief Actualiza el estado del swapchain.
    */
    void
        update();

    /**
    * @brief Renderiza el contenido utilizando el swapchain.
    */
    void
        render();

    /**
    * @brief Destruye el swapchain y libera los recursos asociados.
    */
    void
        destroy();

    /**
    * @brief Presenta el contenido del swapchain.
    */
    void
        present();

    IDXGISwapChain* m_swapchain = nullptr; // Swapchain
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL; // Driver Type

private:
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0; // Feature Level

    // MSAA Configuration
    // Para evitar que los p�xeles se vean con un efecto de "serrucho" (aliasing) en DirectX 11 con C++,
    // se puede utilizar una t�cnica llamada anti-aliasing.

    // Multisample Anti-Aliasing (MSAA)
    // MSAA es una t�cnica que suaviza los bordes de los objetos al muestrear varios puntos por p�xel.
    // Para habilitar MSAA en DirectX 11:

    unsigned int m_sampleCount; // Number of MSAA samples (4x MSAA)
    unsigned int m_qualityLevels; // Quality levels of MSAA

    // Punteros a las interfaces DXGI
    IDXGIDevice* m_dxgiDevice = nullptr; // DXGI Device
    IDXGIAdapter* m_dxgiAdapter = nullptr; // DXGI Adapter
    IDXGIFactory* m_dxgiFactory = nullptr; // DXGI Factory

};
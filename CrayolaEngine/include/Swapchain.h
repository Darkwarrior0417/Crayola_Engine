#pragma once
#include "Prerequisites.h"

// Forward Declarations - Declaraciones previas
class Device;
class DeviceContext;
class Window;
class Texture;

/*
 * @brief Clase que gestiona la cadena de intercambio de Direct3D 11.
 */
class SwapChain {
public:
    /**
     * @brief Constructor por defecto.
     */
    SwapChain() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~SwapChain() = default;

    /**
     * @brief Inicializa la cadena de intercambio.
     */
    HRESULT init(Device& device,
        DeviceContext& deviceContext,
        Texture& backBuffer,
        Window& window); 

    /**
     * @brief Actualiza los parámetros de la cadena de intercambio si es necesario.
     */
    void update();

    /**
     * @brief Renderiza el contenido en el buffer de la cadena de intercambio.
     */
    void render();

    /**
     * @brief Libera los recursos asociados con la cadena de intercambio.
     */
    void destroy();

    /**
     * @brief Presenta el buffer trasero en la pantalla.
     *
     * Se encarga de intercambiar el buffer trasero con el buffer frontal para mostrar la imagen renderizada.
     */
    void present();

public:
    IDXGISwapChain* m_swapchain = nullptr;
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

private:
    /// Nivel de características de Direct3D utilizado (por defecto 11.0).
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;
    // MSAA Configuration
    /*
     * Para evitar que los píxeles se vean con un efecto de "serrucho" (aliasing) en DirectX 11 con C++,
     * se puede utilizar una técnica llamada anti-aliasing.
     *
     * Multisample Anti-Aliasing (MSAA)
     * MSAA es una técnica que suaviza los bordes de los objetos al muestrear varios puntos por píxel.
     * Para habilitar MSAA en DirectX 11:
     *
     */

    /// Número de muestras utilizadas para el antialiasing.
    unsigned int m_sampleCount;

    /// Niveles de calidad de las muestras de antialiasing.
    unsigned int m_qualityLevels;

    // Punteros a las interfaces DXGI para la gestión de dispositivos y adaptadores gráficos.
    IDXGIDevice* m_dxgiDevice = nullptr;
    IDXGIAdapter* m_dxgiAdapter = nullptr;
    IDXGIFactory* m_dxgiFactory = nullptr;
};

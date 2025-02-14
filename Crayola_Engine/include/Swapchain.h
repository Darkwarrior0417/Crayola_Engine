#pragma once
#include "Prerequisites.h"

// Forward Declarations - Declaraciones previas
class Device;
class DeviceContext;
class Window;
class Texture;

/**
 * @class SwapChain
 * @brief Clase que gestiona la cadena de intercambio de Direct3D 11.
 *
 * La cadena de intercambio es responsable de la presentación de imágenes en pantalla,
 * permitiendo la renderización en un buffer y su posterior visualización.
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
     *
     * @param device Referencia al dispositivo Direct3D utilizado.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param backBuffer Referencia a la textura del back buffer.
     * @param window Referencia a la ventana de renderizado.
     * @return HRESULT Código de resultado indicando éxito o error en la operación.
     */
    HRESULT init(Device& device,
        DeviceContext& deviceContext,
        Texture& backBuffer,
        Window& window); // <-- CORREGIDO: Se pasa por referencia (&)

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
    /// Puntero a la interfaz IDXGISwapChain que representa la cadena de intercambio.
    IDXGISwapChain* m_swapchain = nullptr;

    /// Tipo de driver utilizado por Direct3D.
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

private:
    /// Nivel de características de Direct3D utilizado (por defecto 11.0).
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;

    /// Número de muestras utilizadas para el antialiasing.
    unsigned int m_sampleCount;

    /// Niveles de calidad de las muestras de antialiasing.
    unsigned int m_qualityLevels;

    // Punteros a las interfaces DXGI para la gestión de dispositivos y adaptadores gráficos.

    /// Puntero a la interfaz IDXGIDevice para la gestión del dispositivo DXGI.
    IDXGIDevice* m_dxgiDevice = nullptr;

    /// Puntero a la interfaz IDXGIAdapter para la gestión del adaptador gráfico.
    IDXGIAdapter* m_dxgiAdapter = nullptr;

    /// Puntero a la interfaz IDXGIFactory para la creación de la cadena de intercambio.
    IDXGIFactory* m_dxgiFactory = nullptr;
};

#pragma once
#include "Prerequisites.h"

// Declaraciones anticipadas - Clases DirectX
class Device; // Representa el dispositivo DirectX.
class DeviceContext; // Maneja el contexto de comandos para el dispositivo.
class Window;  // Clase para controlar la ventana de la aplicación.
class Texture;  // Gestiona las texturas en DirectX.


// Clase Swapchain que se encarga del intercambio de buffers para la renderización en pantalla.
class
    Swapchain {
public:
    Swapchain() = default;
    ~Swapchain() = default;

    /**
<<<<<<< Updated upstream
<<<<<<< Updated upstream
     * @brief Inicializa el swapchain.
     *
     * @param device Dispositivo.
     * @param deviceContext Contexto del dispositivo.
     * @param backBuffer Textura de la ventana.
     * @param window Ventana.
     */
    void
=======
=======
>>>>>>> Stashed changes
    * @brief Configura e inicializa el swapchain.
    * @param device Referencia al dispositivo DirectX.
    * @param deviceContext Referencia al contexto del dispositivo.
    * @param backBuffer Referencia a la textura usada como búfer posterior.
    * @param window Referencia a la ventana de la aplicación.
    * @return HRESULT Valor de resultado indicando éxito o fallo.
    */

    HRESULT
>>>>>>> Stashed changes
        init(Device& device,
            DeviceContext& deviceContext,
            Texture& backBuffer,
            Window& window);

    /**
    * @brief Actualiza el estado actual del swapchain.
    */
    void
        update();

    /**
    * @brief Ejecuta el proceso de renderización usando el swapchain.
    */
    void
        render();

    /**
    * @brief Libera los recursos relacionados con el swapchain.
    */
    void
        destroy();

    /**
    * @brief Muestra el frame actual en la pantalla.
    */
    void
        present();

public:
    // Puntero a la interfaz de swapchain de DirectX.
    IDXGISwapChain* m_swapchain = nullptr;
    // Tipo de controlador gráfico utilizado.
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

private:
    // Nivel de características de Direct3D (por defecto, Direct3D 11.0).
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;

    // Cantidad de muestras para el antialiasing MSAA.
    unsigned int m_sampleCount;
    // Niveles de calidad para el MSAA.
    unsigned int m_qualityLevels;

    // Punteros a las interfaces DXGI
    IDXGIDevice* m_dxgiDevice = nullptr; // Dispositivo DXGI.
    IDXGIAdapter* m_dxgiAdapter = nullptr; // Adaptador DXGI.
    IDXGIFactory* m_dxgiFactory = nullptr;  // Fábrica DXGI para crear objetos asociados.
};

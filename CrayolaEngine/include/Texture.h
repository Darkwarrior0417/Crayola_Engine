#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/**
* @brief Clase que encapsula la creación, manejo y renderizado de texturas en DirectX 11.
*/
class
Texture {
public:
    
    /**
     * @brief Constructor por defecto.
     */
    Texture() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~Texture() = default;

    /**
     * @brief Inicializa una textura a partir de un archivo de imagen.
     */
    HRESULT
    init(Device device,
            const std::string& textureName,
            ExtensionType extensionType);

    /**
     * @brief Inicializa una textura manualmente especificando sus parámetros.
     */
    HRESULT
    init(Device device,
            unsigned int width,
            unsigned int height,
            DXGI_FORMAT Format,
            unsigned int BindFlags,
            unsigned int sampleCount = 1,
            unsigned int qualityLevels = 0);

    /**
     * @brief Actualiza el estado interno de la textura (normalmente no se usa).
     */
    void
    update();

    /**
     * @brief Establece la textura activa para el pipeline de renderizado.
     */
    void
    render(DeviceContext& deviceContet,
            unsigned int StartSlot,
            unsigned int NumViews);

    /**
     * @brief Libera los recursos de la textura y limpia la memoria utilizada.
     */
    void
    destroy();

public:
    ID3D11Texture2D* m_texture = nullptr;    // Recurso de textura como un 2D Texture en DirectX 11
    ID3D11ShaderResourceView* m_textureFromImg;     // Vista de recurso para utilizar la textura en shaders
};
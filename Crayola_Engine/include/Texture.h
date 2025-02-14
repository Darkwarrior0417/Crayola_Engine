#pragma once
#include "Prerequisites.h"

class
    Device;
class
    DeviceContext;

/**
 * @class Texture
 * @brief Clase que representa una textura en Direct3D 11.
 *
 * Gestiona la creaci�n, actualizaci�n, renderizado y destrucci�n de texturas en la GPU.
 */
class
    Texture {
public:
<<<<<<< Updated upstream
    Texture() = default;
    ~Texture() = default;

    HRESULT
        init(Device device,
            const std::string& textureName,
            ExtensionType extensionType);

    HRESULT
        init(Device device,
            unsigned int width,
            unsigned int height,
            DXGI_FORMAT Format,
            unsigned int BindFlags,
            unsigned int sampleCount = 1,
            unsigned int qualityLevels = 0);

    void
        update();

    void
        render(DeviceContext& deviceContet,
            unsigned int StartSlot,
            unsigned int NumViews);

=======
    /**
     * @brief Constructor por defecto.
     */
    Texture() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~Texture() = default;

    /**
     * @brief Inicializa una textura desde un archivo de imagen.
     *
     * @param device Referencia al dispositivo Direct3D.
     * @param textureName Nombre del archivo de la textura.
     * @param extensionType Tipo de extensi�n del archivo de la textura.
     * @return HRESULT C�digo de resultado indicando �xito o error en la operaci�n.
     */
    HRESULT init(Device device,
        const std::string& textureName,
        ExtensionType extensionType);

    /**
     * @brief Inicializa una textura con dimensiones y formato espec�ficos.
     *
     * @param device Referencia al dispositivo Direct3D.
     * @param width Ancho de la textura en p�xeles.
     * @param height Alto de la textura en p�xeles.
     * @param Format Formato de la textura (DXGI_FORMAT).
     * @param BindFlags Flags que indican el uso de la textura.
     * @param sampleCount N�mero de muestras para antialiasing (opcional, por defecto 1).
     * @param qualityLevels Niveles de calidad del muestreo (opcional, por defecto 0).
     * @return HRESULT C�digo de resultado indicando �xito o error en la operaci�n.
     */
    HRESULT init(Device device,
        unsigned int width,
        unsigned int height,
        DXGI_FORMAT Format,
        unsigned int BindFlags,
        unsigned int sampleCount = 1,
        unsigned int qualityLevels = 0);

    /**
     * @brief Actualiza la textura si es necesario.
     */
    void
        update();

    /**
     * @brief Renderiza la textura en la etapa de shader.
     *
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param StartSlot Primer slot en el que se asignar� la textura.
     * @param NumViews N�mero de vistas de la textura a asignar.
     */
    void
        render(DeviceContext& deviceContext,
            unsigned int StartSlot,
            unsigned int NumViews);

    /**
     * @brief Libera los recursos asociados con la textura.
     */
>>>>>>> Stashed changes
    void
        destroy();

public:
<<<<<<< Updated upstream
    // This variable is in charge of handle a texture resource as data
    ID3D11Texture2D* m_texture = nullptr;
    // This variable is in charge of handle a texture resource as image data
    ID3D11ShaderResourceView* m_textureFromImg;

private:
=======
    /// Puntero a la interfaz ID3D11Texture2D que representa la textura como recurso de datos.
    ID3D11Texture2D* m_texture = nullptr;
>>>>>>> Stashed changes

    /// Puntero a la interfaz ID3D11ShaderResourceView que representa la textura como imagen para los shaders.
    ID3D11ShaderResourceView* m_textureFromImg;
};
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"
#include "Device.h"
#include "DeviceContext.h"

/**
 * @brief Inicializa una textura cargándola desde un archivo (DDS o PNG).
 * @param device Dispositivo de renderizado.
 * @param textureName Ruta del archivo de la textura.
 * @param extensionType Tipo de extensión (DDS o PNG).
 * @return HRESULT indicando éxito o error.
 */
HRESULT 
Texture::init(Device device,
    const std::string& textureName,
    ExtensionType extensionType) {

    if (!device.m_device) {
        ERROR("Texture", "init", "Device is nullptr in texture loading method");
        return E_POINTER;
    }

    HRESULT hr = S_OK;

    switch (extensionType) {
    case DDS:
        // Cargar textura DDS directamente usando DirectX helper
        hr = D3DX11CreateShaderResourceViewFromFile(
            device.m_device,
            textureName.c_str(),
            nullptr,
            nullptr,
            &m_textureFromImg,
            nullptr
        );

        if (FAILED(hr)) {
            ERROR("Texture", "init", ("Failed to load DDS texture. Verify filepath: " + textureName).c_str());
            return hr;
        }
        break;

    case PNG: {
        // Cargar imagen PNG usando stb_image
        int width, height, channels;
        unsigned char* data = stbi_load(textureName.c_str(), &width, &height, &channels, 4);
        if (!data) {
            ERROR("Texture", "init", ("Failed to load PNG texture: " + std::string(stbi_failure_reason())).c_str());
            return E_FAIL;
        }

        // Descripción de la textura
        D3D11_TEXTURE2D_DESC textureDesc = {};
        textureDesc.Width = width;
        textureDesc.Height = height;
        textureDesc.MipLevels = 1;
        textureDesc.ArraySize = 1;
        textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        textureDesc.SampleDesc.Count = 1;
        textureDesc.Usage = D3D11_USAGE_DEFAULT;
        textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

        // Datos iniciales de la textura
        D3D11_SUBRESOURCE_DATA initData = {};
        initData.pSysMem = data;
        initData.SysMemPitch = width * 4;

        // Crear textura
        hr = device.CreateTexture2D(&textureDesc, &initData, &m_texture);
        stbi_image_free(data); // Liberar la memoria de imagen

        if (FAILED(hr)) {
            ERROR("Texture", "init", "Failed to create texture from PNG data");
            return hr;
        }

        // Crear vista para usar la textura como recurso de shader
        D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
        srvDesc.Format = textureDesc.Format;
        srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
        srvDesc.Texture2D.MipLevels = 1;

        hr = device.m_device->CreateShaderResourceView(m_texture, &srvDesc, &m_textureFromImg);
        SAFE_RELEASE(m_texture); // Liberar textura intermedia

        if (FAILED(hr)) {
            ERROR("Texture", "init", "Failed to create shader resource view for PNG texture");
            return hr;
        }

        break;
    }

    default:
        ERROR("Texture", "init", "Unsupported extension type");
        return E_INVALIDARG;
    }

    return hr;
}

/**
 * @brief Inicializa una textura vacía con parámetros definidos.
 * @return HRESULT indicando éxito o error.
 */
HRESULT 
Texture::init(Device device,
    unsigned int width,
    unsigned int height,
    DXGI_FORMAT Format,
    unsigned int BindFlags,
    unsigned int sampleCount,
    unsigned int qualityLevels) {

    if (!device.m_device) {
        ERROR("Texture", "init", "Device is nullptr in texture inicialization method");
        return E_POINTER;
    }

    if (width == 0 || height == 0) {
        ERROR("Texture", "init", "Width and height must be greater than 0");
        return E_INVALIDARG;
    }

    HRESULT hr = S_OK;

    // Descripción de la textura
    D3D11_TEXTURE2D_DESC desc = {};
    desc.Width = width;
    desc.Height = height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = Format;
    desc.SampleDesc.Count = sampleCount;
    desc.SampleDesc.Quality = qualityLevels;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = BindFlags;

    // Crear la textura vacía
    hr = device.CreateTexture2D(&desc, nullptr, &m_texture);
    if (FAILED(hr)) {
        ERROR("Texture", "init", "Failed to create texture with the specified parameters");
        return hr;
    }

    return hr;
}

/**
 * @brief Método vacío: reservado para futuras actualizaciones internas de textura.
 */
void 
Texture::update() {
    // Implementación opcional
}

/**
 * @brief Asigna la textura al pipeline de renderizado para el Pixel Shader.
 * @param deviceContext Contexto de dispositivo.
 * @param StartSlot Slot de inicio para el shader resource.
 * @param NumViews Número de vistas a asignar.
 */
void 
Texture::render(DeviceContext& deviceContext,
    unsigned int StartSlot,
    unsigned int NumViews) {

    if (m_textureFromImg) {
        // En caso de que ya haya una textura cargada, primero limpia el slot
        ID3D11ShaderResourceView* nullSRV[] = { nullptr };
        deviceContext.PSSetShaderResources(StartSlot, NumViews, nullSRV);
        deviceContext.PSSetShaderResources(StartSlot, NumViews, &m_textureFromImg);
    }
    else {
        ERROR("Texture", "render", "Texture resource is not initialized");
    }
}

/**
 * @brief Libera todos los recursos asociados a la textura.
 */// Libera los recursos asociados a la textura
void 
Texture::destroy() {
    SAFE_RELEASE(m_texture);
    SAFE_RELEASE(m_textureFromImg);
}

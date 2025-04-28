#include "Swapchain.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Window.h"
#include "Texture.h"

/**
 * @brief Inicializa el SwapChain creando dispositivo, contexto, y configurando MSAA.
 * @param device Referencia al objeto Device para almacenar el dispositivo creado.
 * @param deviceContext Referencia al objeto DeviceContext para almacenar el contexto creado.
 * @param backBuffer Textura que contendrá el render target.
 * @param window Ventana donde se presentará el contenido.
 * @return HRESULT indicando éxito o fallo de la inicialización.
 */
HRESULT
SwapChain::init(Device& device,
    DeviceContext& deviceContext,
    Texture& backBuffer,
    Window& window) {

    if (!window.m_hWnd) {
        ERROR("SwapChain", "init", "Invalid Window handle (m_hWnd is nullptr)");
        return E_POINTER;
    }

    HRESULT hr = S_OK;

    // Crear dispositivo y contexto DirectX 11
    unsigned int createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    // Tipos de driver a intentar
    D3D_DRIVER_TYPE driverTypes[] = {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };
    unsigned int numDriverTypes = ARRAYSIZE(driverTypes);

    // Niveles de característica de DirectX soportados
    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0
    };
    unsigned int numFeatureLevels = ARRAYSIZE(featureLevels);

    // Intentar crear el dispositivo con cada tipo de driver
    for (unsigned int i = 0; i < numDriverTypes; i++) {
        m_driverType = driverTypes[i];
        hr = D3D11CreateDevice(
            nullptr,
            m_driverType,
            nullptr,
            createDeviceFlags,
            featureLevels,
            numFeatureLevels,
            D3D11_SDK_VERSION,
            &device.m_device,
            &m_featureLevel,
            &deviceContext.m_deviceContext
        );

        if (SUCCEEDED(hr))
            break;
    }

    if (FAILED(hr)) {
        ERROR("SwapChain", "init", "Failed to create D3D11 device");
        return hr;
    }

    // Verificar compatibilidad con MSAA
    m_sampleCount = 4;
    hr = device.m_device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, m_sampleCount, &m_qualityLevels);
    if (FAILED(hr) || m_qualityLevels == 0) {
        ERROR("SwapChain", "init", "MSAA not supported or invalid quality level");
        return hr;
    }

    // Configuración del SwapChain
    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferCount = 1;
    sd.BufferDesc.Width = window.m_width;
    sd.BufferDesc.Height = window.m_height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = window.m_hWnd;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    sd.SampleDesc.Count = m_sampleCount;
    sd.SampleDesc.Quality = m_qualityLevels - 1;

    // Obtener interfaces DXGI
    hr = device.m_device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&m_dxgiDevice));
    if (FAILED(hr)) {
        ERROR("SwapChain", "init", "Failed to query IDXGIDevice");
        return hr;
    }

    hr = m_dxgiDevice->GetAdapter(&m_dxgiAdapter);
    if (FAILED(hr)) {
        ERROR("SwapChain", "init", "Failed to get DXGI Adapter");
        return hr;
    }

    hr = m_dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&m_dxgiFactory));
    if (FAILED(hr)) {
        ERROR("SwapChain", "init", "Failed to get DXGI Factory");
        return hr;
    }

    // Crear el SwapChain
    hr = m_dxgiFactory->CreateSwapChain(device.m_device, &sd, &m_swapchain);
    if (FAILED(hr)) {
        ERROR("SwapChain", "init", "Failed to create SwapChain");
        return hr;
    }

    // Obtener el back buffer como textura
    hr = m_swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer.m_texture));
    if (FAILED(hr)) {
        ERROR("SwapChain", "init", "Failed to get SwapChain buffer");
        return hr;
    }

    return S_OK;
}

/**
 * @brief Método vacío: reservado para futura lógica de actualización del SwapChain.
 */
void 
SwapChain::update() {
}

/**
 * @brief Método vacío: reservado para lógica de renderizado directo desde el SwapChain.
 */
void
SwapChain::render() {
}

/**
 * @brief Libera los recursos asociados al SwapChain y sus interfaces DXGI.
 */
void
SwapChain::destroy() {
    SAFE_RELEASE(m_swapchain);
    SAFE_RELEASE(m_dxgiFactory);
    SAFE_RELEASE(m_dxgiAdapter);
    SAFE_RELEASE(m_dxgiDevice);
}

/**
 * @brief Presenta el contenido del back buffer en pantalla.
 */
void
SwapChain::present() {
    if (m_swapchain) {
        HRESULT hr = m_swapchain->Present(0, 0);
        if (FAILED(hr)) {
            ERROR("SwapChain", "present", "Failed to present SwapChain");
        }
    }
    else {
        ERROR("SwapChain", "present", "SwapChain is nullptr");
    }
}

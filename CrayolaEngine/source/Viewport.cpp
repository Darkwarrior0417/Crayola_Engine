#include "Viewport.h"
#include "Window.h"
#include "DeviceContext.h"

/**
 * @brief Inicializa el viewport utilizando las dimensiones de una ventana existente.
 * @param window Referencia a la ventana.
 * @return HRESULT indicando éxito o error.
 */
HRESULT
Viewport::init(const Window& window) {
    if (!window.m_hWnd) {
        ERROR("Viewport", "init", "Window handle (m_hWnd) is nullptr");
        return E_POINTER;
    }
    if (window.m_width == 0 || window.m_height == 0) {
        ERROR("Viewport", "init", "Width or height is zero");
        return E_INVALIDARG;
    }

    // Configuración básica del viewport
    m_viewport.Width = static_cast<float>(window.m_width);
    m_viewport.Height = static_cast<float>(window.m_height);
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 1.0f;
    m_viewport.TopLeftX = 0;
    m_viewport.TopLeftY = 0;

    return S_OK;
}

/**
 * @brief Inicializa el viewport a partir de valores de ancho y alto específicos.
 * @param width Ancho del viewport.
 * @param height Alto del viewport.
 * @return HRESULT indicando éxito o error.
 */
HRESULT 
Viewport::init(unsigned int width, unsigned int height) {
    if (width == 0 || height == 0) {
        ERROR("Viewport", "init", "Width or height is zero");
        return E_INVALIDARG;
    }

    // Configuración del área de dibujo
    m_viewport.Width = static_cast<float>(width);
    m_viewport.Height = static_cast<float>(height);
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 1.0f;
    m_viewport.TopLeftX = 0;
    m_viewport.TopLeftY = 0;

    return S_OK;
}

/**
 * @brief Método opcional para actualizar dinámicamente el viewport en tiempo de ejecución.
 */
void
Viewport::update() {
    
}
/**
 * @brief Establece el viewport en el pipeline de renderizado.
 * @param deviceContext Contexto del dispositivo para establecer el viewport.
 */
void 
Viewport::render(DeviceContext& deviceContext) {
    if (!deviceContext.m_deviceContext) {
        ERROR("Viewport", "render", "DeviceContext is nullptr");
        return;
    }

    deviceContext.RSSetViewports(1, &m_viewport);
}

/**
 * @brief Libera los recursos asociados al viewport.
 */
void 
Viewport::destroy() {
   
}

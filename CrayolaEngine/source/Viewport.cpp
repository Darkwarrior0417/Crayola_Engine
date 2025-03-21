#include "Viewport.h"
#include "Window.h"
#include "DeviceContext.h"

// Inicializa el viewport utilizando las dimensiones de una ventana existente
HRESULT Viewport::init(const Window& window) {
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

// Inicializa el viewport directamente a partir de valores de ancho y alto
HRESULT Viewport::init(unsigned int width, unsigned int height) {
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

// Método opcional para actualizar dinámicamente el viewport en tiempo de ejecución
void Viewport::update() {
    
}

// Establece el viewport en el contexto de renderizado activo
void Viewport::render(DeviceContext& deviceContext) {
    if (!deviceContext.m_deviceContext) {
        ERROR("Viewport", "render", "DeviceContext is nullptr");
        return;
    }

    deviceContext.RSSetViewports(1, &m_viewport);
}

// Libera recursos asociados al viewport
void Viewport::destroy() {
   
}

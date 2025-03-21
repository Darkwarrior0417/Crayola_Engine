#include "RenderTargetView.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Texture.h"
#include "DepthStencilView.h"

// Inicializa el RenderTargetView utilizando la textura del back buffer y un formato específico
HRESULT RenderTargetView::init(Device& device, Texture& backBuffer, DXGI_FORMAT Format) {
    if (!device.m_device) {
        ERROR("RenderTargetView", "init", "Device is nullptr");
        return E_POINTER;
    }

    if (!backBuffer.m_texture) {
        ERROR("RenderTargetView", "init", "BackBuffer texture is nullptr");
        return E_POINTER;
    }

    HRESULT hr = S_OK;

    // Configuración de la vista del render target
    D3D11_RENDER_TARGET_VIEW_DESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.Format = Format;
    desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2DMS;

    // Crear el RenderTargetView
    hr = device.CreateRenderTargetView(backBuffer.m_texture, &desc, &m_renderTargetView);
    if (FAILED(hr)) {
        ERROR("RenderTargetView", "init", "Failed to create RenderTargetView");
        return hr;
    }

    return S_OK;
}

// Método vacío: se puede usar en el futuro para lógica dinámica del RenderTargetView
void RenderTargetView::update() {
    // Intencionalmente vacío por ahora
}

// Limpia el RenderTargetView y lo establece junto con el DepthStencilView para el render
void RenderTargetView::render(DeviceContext& deviceContext,
    DepthStencilView& depthStencilView,
    unsigned int numViews,
    const float ClearColor[4]) {

    if (!m_renderTargetView) {
        ERROR("RenderTargetView", "render", "RenderTargetView is nullptr");
        return;
    }

    if (!deviceContext.m_deviceContext) {
        ERROR("RenderTargetView", "render", "DeviceContext is nullptr");
        return;
    }

    // Limpiar el render target con el color definido
    deviceContext.ClearRenderTargetView(m_renderTargetView, ClearColor);

    // Asignar el render target y depth stencil al pipeline
    deviceContext.OMSetRenderTargets(numViews,
        &m_renderTargetView,
        depthStencilView.m_depthStencilView);
}

// Libera los recursos asignados al RenderTargetView
void RenderTargetView::destroy() {
    SAFE_RELEASE(m_renderTargetView);
}

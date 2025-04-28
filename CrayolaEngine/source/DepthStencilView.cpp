#include "DepthStencilView.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Texture.h"

/*
 @brief Inicializa la DepthStencilView usando una textura de profundidad existente.
 @param device Referencia al dispositivo de DirectX.
 @param depthStencil Textura que se usará como DepthStencil.
 @param format Formato DXGI para la vista.
 @return HRESULT que indica éxito o error.
*/
HRESULT 
DepthStencilView::init(Device& device, Texture& depthStencil, DXGI_FORMAT format) {
    if (!device.m_device) {
        ERROR("DepthStencilView", "init", "Device is nullptr");
        return E_POINTER;
    }

    if (!depthStencil.m_texture) {
        ERROR("DepthStencilView", "init", "DepthStencil texture is nullptr");
        return E_POINTER;
    }

    HRESULT hr = S_OK;

    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    memset(&descDSV, 0, sizeof(descDSV));
    descDSV.Format = format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
    descDSV.Texture2D.MipSlice = 0;

    hr = device.CreateDepthStencilView(depthStencil.m_texture, &descDSV, &m_depthStencilView);
    if (FAILED(hr)) {
        ERROR("DepthStencilView", "init", "Failed to create DepthStencilView");
        return hr;
    }

    return S_OK;
}

/*
 @brief Limpia el DepthStencilView con el valor de profundidad por defecto.
 @param deviceContext Contexto de dispositivo para emitir el comando.
*/
void 
DepthStencilView::render(DeviceContext& deviceContext) {
    if (!m_depthStencilView) {
        ERROR("DepthStencilView", "render", "DepthStencilView is nullptr");
        return;
    }

    if (!deviceContext.m_deviceContext) {
        ERROR("DepthStencilView", "render", "DeviceContext is nullptr");
        return;
    }

    deviceContext.ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

/*
 @brief Libera los recursos asociados a la DepthStencilView.
*/
void
DepthStencilView::destroy() {
    SAFE_RELEASE(m_depthStencilView);
}

#include "InputLayout.h"
#include "Device.h"
#include "DeviceContext.h"

/*
 @brief Inicializa el Input Layout a partir de una descripción y los datos del Vertex Shader.
 @param device Dispositivo de DirectX.
 @param Layout Vector con la descripción de los elementos de entrada.
 @param VertexShaderData Blob que contiene el bytecode del vertex shader.
 @return HRESULT que indica éxito o error.
*/
HRESULT 
InputLayout::init(Device& device,
    std::vector<D3D11_INPUT_ELEMENT_DESC>& Layout,
    ID3DBlob* VertexShaderData) {

    if (Layout.empty()) {
        ERROR("InputLayout", "init", "Layout vector is empty");
        return E_INVALIDARG;
    }

    if (!VertexShaderData) {
        ERROR("InputLayout", "init", "VertexShaderData is nullptr");
        return E_POINTER;
    }

    HRESULT hr = device.CreateInputLayout(
        Layout.data(),
        static_cast<unsigned int>(Layout.size()),
        VertexShaderData->GetBufferPointer(),
        VertexShaderData->GetBufferSize(),
        &m_inputLayout
    );

    if (FAILED(hr)) {
        ERROR("InputLayout", "init", "Failed to create InputLayout");
        return hr;
    }

    return S_OK;
}

/*
 @brief Método vacío que puede utilizarse para actualizar el layout dinámicamente si es necesario.
*/
void 
InputLayout::update() {
    // Implementación opcional
}

/*
 @brief Establece el Input Layout en el pipeline gráfico.
 @param deviceContext Contexto del dispositivo donde se asignará el layout.
*/
void 
InputLayout::render(DeviceContext& deviceContext) {
    if (!m_inputLayout) {
        ERROR("InputLayout", "render", "InputLayout is nullptr");
        return;
    }

    deviceContext.IASetInputLayout(m_inputLayout);
}

/*
 @brief Libera los recursos asociados al Input Layout.
*/
void InputLayout::destroy() {
    SAFE_RELEASE(m_inputLayout);
}

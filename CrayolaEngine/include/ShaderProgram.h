#pragma once
#include "Prerequisites.h"
#include "InputLayout.h"

class Device;
class DeviceContext;

/**
 * @brief Clase que encapsula la carga, compilación, y uso de shaders en DirectX 11,
 * incluyendo vertex shaders, pixel shaders e input layouts.
 */
class 
ShaderProgram {
public:
    /**
     * @brief Constructor por defecto.
     */
    ShaderProgram() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~ShaderProgram() = default;

    // Inicializa el shader program con archivo y layout de entrada.
    HRESULT 
    init(Device& device,
        const std::string& fileName,
        std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

    // Actualiza el estado interno del shader (si aplica).
    void 
    update();

    // Asigna los shaders y layout al pipeline de renderizado.
    void 
    render(DeviceContext& deviceContext);

    // Libera los recursos del shader program.
    void 
    destroy();

    // Crea el input layout con base en la descripción del layout y shader compilado.
    HRESULT 
    CreateInputLayout(Device& device, std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

    // Crea un shader (vertex o pixel) según el tipo.
    HRESULT 
    CreateShader(Device& device, ShaderType type);

    // Compila un shader desde archivo.
    HRESULT 
    CompileShaderFromFile(char* szFileName,
        LPCSTR szEntryPoint,
        LPCSTR szShaderModel,
        ID3DBlob** ppBlobOut);

public:
    ID3D11VertexShader* m_VertexShader = nullptr;   // Vertex Shader compilado
    ID3D11PixelShader* m_PixelShader = nullptr;     // Pixel Shader compilado
    InputLayout m_inputLayout;                      // Input layout usado por el vertex shader

private:
    std::string m_shaderFileName;                   // Nombre del archivo .fx o .hlsl
    ID3DBlob* m_vertexShaderData = nullptr;         // Datos compilados del vertex shader
    ID3DBlob* m_pixelShaderData = nullptr;          // Datos compilados del pixel shader
};

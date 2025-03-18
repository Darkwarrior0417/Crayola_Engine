#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Swapchain.h"
#include "Texture.h"
#include "RenderTargetView.h"
#include "DepthStencilView.h"
#include "Viewport.h"
#include "ShaderProgram.h"
#include "Buffer.h"
#include "MeshComponent.h"
#include "SamplerState.h"

class 
BaseApp {
public:
    /*
     * @brief Constructor por defecto.
     */
    BaseApp() = default;

    /*
     * @brief Destructor por defecto.
     */
    ~BaseApp() = default;

    /*
     * @brief Inicializa la aplicación.
     */
    HRESULT 
    init();

    /*
     * @brief Actualiza la lógica de la aplicación en cada frame.
     */
    void 
    update();

    /*
     * @brief Renderiza el contenido gráfico de la aplicación.
     */
    void 
    render();

    /*
     * @brief Libera los recursos utilizados por la aplicación.
     */
    void
    destroy();

    void
    inputActionMap(float deltaTime);

    void
    updateCamera();

    void
    rotateCamera(int mouseX, int mouseY);

    /**
     * @brief Ejecuta la aplicación.
     */
    int
    run(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            LPWSTR lpCmdLine,
            int nCmdShow,
            WNDPROC wndproc);

    HRESULT
    resize(HWND hWnd, LPARAM lparam);

public:
    Window                              m_window;
    Device                              m_device;
    DeviceContext                       m_deviceContext;
    SwapChain                           m_swapchain;
    Texture                             m_backBuffer;
    Texture                             m_depthStencil;
    RenderTargetView                    m_renderTargetView;
    DepthStencilView                    m_depthStencilView;
    Viewport                            m_viewport;
    ShaderProgram                       m_shaderProgram;
    Buffer                              m_vertexBuffer;
    Buffer                              m_indexBuffer;
    Buffer                              m_neverChange;
    Buffer                              m_changeOnResize;
    Buffer                              m_changesEveryFrame;
    Texture                             m_modelTexture;
    SamplerState						m_samplerState;

    ID3D11SamplerState* g_pSamplerLinear = NULL;
    XMMATRIX                            m_modelMatrix;
    XMMATRIX                            m_View;
    XMMATRIX                            m_Projection;
    XMFLOAT4                            m_vMeshColor;

    XMFLOAT3 position;
    XMFLOAT3 rotation;
    XMFLOAT3 scale;
    MeshComponent m_meshComponent;

    Camera m_camera;

    bool keys[256] = { false };
  float sensitivity = 0.002f;
  int lastX;
  int lastY;
  bool mouseLeftDown = false;


    CBChangesEveryFrame cb;
    CBNeverChanges cbNeverChanges;
    CBChangeOnResize cbChangesOnResize;
};
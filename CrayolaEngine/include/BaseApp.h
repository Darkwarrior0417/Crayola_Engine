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
#include "UI.h"
#include "ModelLoader.h"
#include "ECS/Actor.h"

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


    /**
     * @brief Mapea las acciones de entrada del usuario.
     * @param deltaTime Tiempo entre frames.
     */
    void
    inputActionMap(float deltaTime);

    /**
     * @brief Actualiza la posición y rotación de la cámara.
     */
    void
    updateCamera();

    /**
     * @brief Rota la cámara usando el movimiento del mouse.
     * @param mouseX Posición X del mouse.
     * @param mouseY Posición Y del mouse.
     */
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

    /**
     * @brief Maneja el redimensionamiento de la ventana.
     */
    HRESULT
    resize(HWND hWnd, LPARAM lparam);

public:
    // Componentes base del motor
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


    // Buffers gráficos
        /*Buffer                              m_vertexBuffer;
        Buffer                              m_indexBuffer;*/
    Buffer                              m_neverChange;
    Buffer                              m_changeOnResize;
    Buffer                              m_changesEveryFrame;

    // Texturas y estados
    Texture                             m_modelTexture;
    SamplerState						m_samplerState;
    ID3D11SamplerState* g_pSamplerLinear = NULL;
    
    UI                                  m_UI;

    ModelLoader                         m_modelLoader;
    EngineUtilities::TSharedPointer<Actor>         ALethal;
    std::vector<Texture>                            m_modelTextures;

    Texture m_default;

    ModelLoader                         m_modelLoader2;
    EngineUtilities::TSharedPointer<Actor>          AStorm;
    std::vector<Texture>                            m_modelTextures2;

    // Transformaciones y color
    /*XMMATRIX                            m_modelMatrix;*/
    XMMATRIX                            m_View;
    XMMATRIX                            m_Projection;
    XMFLOAT4                            m_vMeshColor;

    // Transformación del objeto / cámara
   /* XMFLOAT3 position;
    XMFLOAT3 rotation;
    XMFLOAT3 scale;*/
    /*MeshComponent m_meshComponent;*/

    Camera m_camera;

    // Input
    bool keys[256] = { false };
    float sensitivity = 0.002f;
    int lastX;
    int lastY;
    bool mouseLeftDown = false;

    // Buffers constantes
    CBChangesEveryFrame cb;
    CBNeverChanges cbNeverChanges;
    CBChangeOnResize cbChangesOnResize;
};
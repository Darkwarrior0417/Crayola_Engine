    #include "BaseApp.h"

    HRESULT
    BaseApp::init() {
        HRESULT hr = S_OK;

        // Inicializar SwapChain y BackBuffer
        hr = m_swapchain.init(m_device, m_deviceContext, m_backBuffer, m_window);
        if (FAILED(hr)) {
            return hr;
        }

        // Crear Render Target View
        hr = m_renderTargetView.init(m_device,
            m_backBuffer,
            DXGI_FORMAT_R8G8B8A8_UNORM);

        if (FAILED(hr)) {
            return hr;
        }

        // Crear DepthStencil y su View
        hr = m_depthStencil.init(m_device,
            m_window.m_width,
            m_window.m_height,
            DXGI_FORMAT_D24_UNORM_S8_UINT,
            D3D11_BIND_DEPTH_STENCIL,
            4,
            0);
        if (FAILED(hr))
            return hr;

        // Create the depth stencil view
        hr = m_depthStencilView.init(m_device,
            m_depthStencil,
            DXGI_FORMAT_D24_UNORM_S8_UINT);

        if (FAILED(hr))
            return hr;

        // Configurar Viewport
        hr = m_viewport.init(m_window);

        if (FAILED(hr))
            return hr;

        // Definir Input Layout para los vértices
        std::vector<D3D11_INPUT_ELEMENT_DESC> Layout;

        D3D11_INPUT_ELEMENT_DESC position;
        position.SemanticName = "POSITION";
        position.SemanticIndex = 0;
        position.Format = DXGI_FORMAT_R32G32B32_FLOAT;
        position.InputSlot = 0;
        position.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT /*0*/;
        position.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
        position.InstanceDataStepRate = 0;
        Layout.push_back(position);

        // Coordenadas de textura
        D3D11_INPUT_ELEMENT_DESC texcoord;
        texcoord.SemanticName = "TEXCOORD";
        texcoord.SemanticIndex = 0;
        texcoord.Format = DXGI_FORMAT_R32G32_FLOAT;
        texcoord.InputSlot = 0;
        texcoord.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT /*12*/;
        texcoord.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
        texcoord.InstanceDataStepRate = 0;
        Layout.push_back(texcoord);

        // Inicializar Shader Program
        hr = m_shaderProgram.init(m_device, "CrayolaEngine.fx", Layout);

        if (FAILED(hr))
            return hr;

        //// Create vertex buffer
        //SimpleVertex
        //    vertices[] = {
        //            { XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT2(0.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
        //            { XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

        //            { XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT2(0.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
        //            { XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

        //            { XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
        //            { XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
        //            { XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 1.0f) },
        //            { XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

        //            { XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 1.0f) },
        //            { XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

        //            { XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT2(0.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT2(1.0f, 1.0f) },
        //            { XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT2(0.0f, 1.0f) },

        //            { XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT2(1.0f, 0.0f) },
        //            { XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
        //            { XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },
        //};
        //    // Create vertex buffer
        //unsigned int
        //    indices[] = {
        //            3,1,0,
        //            2,1,3,

        //            6,4,5,
        //            7,4,6,

        //            11,9,8,
        //            10,9,11,

        //            14,12,13,
        //            15,12,14,

        //            19,17,16,
        //            18,17,19,

        //            22,20,21,
        //            23,20,22
        //};

        //MeshComponent MC;
        //for (SimpleVertex vertex : vertices) {
        //    MC.m_vertex.push_back(vertex);
        //}

        //for (unsigned int index : indices) {
        //    MC.m_index.push_back(index);
        //}

        //MC.m_numVertex = MC.m_vertex.size();
        //MC.m_numIndex = MC.m_index.size();
        //
        /*hr = m_vertexBuffer.init(m_device, MC, D3D11_BIND_VERTEX_BUFFER);
        if (FAILED(hr)) {
            return hr;
        }

        hr = m_indexBuffer.init(m_device, MC, D3D11_BIND_INDEX_BUFFER);
        if (FAILED(hr)) {
            return hr;
        }*/

        // Crear Constant Buffers
        hr = m_neverChange.init(m_device, sizeof(CBNeverChanges));
        if (FAILED(hr))
            return hr;

        hr = m_changeOnResize.init(m_device, sizeof(CBChangeOnResize));
        if (FAILED(hr))
            return hr;

        hr = m_changesEveryFrame.init(m_device, sizeof(CBChangesEveryFrame));
        if (FAILED(hr))
            return hr;

        // Cargar textura de modelo
        hr =m_modelTexture.init(m_device, "seafloor.dds", DDS);
        if (FAILED(hr))
            return hr;

        // Inicializar estado de muestreo
        hr = m_samplerState.init(m_device);
        if (FAILED(hr))
            return hr;

        // Initialize the world matrices
        /*m_modelMatrix = XMMatrixIdentity();

        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;*/

        // Configurar matriz de vista
        XMVECTOR Eye = XMVectorSet(0.0f, 3.0f, -6.0f, 0.0f);
        XMVECTOR At = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
        XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
        m_View = XMMatrixLookAtLH(Eye, At, Up);

        // Inicializar ImGui
        m_UI.init(m_window.m_hWnd, m_device.m_device, m_deviceContext.m_deviceContext);
        // -------------------- OmniMan --------------------

        // 1. Cargar el modelo
        m_modelLoader.LoadFBX_model("Models/Omni.fbx");
        MESSAGE("OmniMan", "Debug", ("Submeshes encontrados: " + std::to_string(m_modelLoader.m_meshes.size())).c_str());

        for (size_t i = 0; i < m_modelLoader.m_meshes.size(); ++i) {
            const std::string& meshName = m_modelLoader.m_meshes[i].m_name;
            MESSAGE("OmniMan", "Submesh", ("[" + std::to_string(i) + "] Nombre: " + meshName).c_str());
        }
        // 2. Asignar texturas por submesh
        m_modelTextures.clear(); // Limpiar antes por si ya existen

        std::vector<std::string> omniTextures = {
            "Textures/Omniman.png",
            "Textures/Omniman2.png",
            "Textures/Omnimanface.png"
        };

        size_t meshCount = m_modelLoader.m_meshes.size();
        size_t texCount = omniTextures.size();

        for (size_t i = 0; i < meshCount; ++i) {
            Texture tex;
            std::string texPath = omniTextures[i < texCount ? i : texCount - 1];

            HRESULT texResult = tex.init(m_device, texPath.c_str(), PNG);
            if (FAILED(texResult)) {
                ERROR("Texture", "OmniMan", ("Fallo al cargar textura: " + texPath).c_str());
            }

            m_modelTextures.push_back(tex);
        }

        // 3. Crear actor y asignar mallas y texturas
        ALethal = EngineUtilities::MakeShared<Actor>(m_device);
        if (!ALethal.isNull()) {
            ALethal->getComponent<Transform>()->setTransform(
                { 2.0f, 1.0f, 0.0f },
                { XM_PI / -2.0f, 0.0f, XM_PI / 2.0f },
                { 1.05f, 1.05f, 1.05f }
            );

            ALethal->setMesh(m_device, m_modelLoader.m_meshes);
            ALethal->setTextures(m_modelTextures);

            MESSAGE("Actor", "ALethal", (ALethal->getName() + " - Actor cargado exitosamente.").c_str());
        }
        else {
            ERROR("Actor", "ALethal", "Fallo al crear el actor.");
        }

        // -------------------- Stormtrooper --------------------
        m_modelLoader2.LoadFBX_model("Models/Storm.fbx");
        if (m_modelLoader2.m_meshes.empty()) {
            ERROR("Stormtrooper", "ModelLoader", "Storm.fbx no contiene mallas.");
        }
        else {
            MESSAGE("Stormtrooper", "ModelLoader", ("Cantidad de mallas cargadas: " + std::to_string(m_modelLoader2.m_meshes.size())).c_str());
        }

        // Validar que sí se hayan cargado meshes
        MESSAGE("ModelLoader", "Storm", ("Meshes loaded: " + std::to_string(m_modelLoader2.m_meshes.size())).c_str());

        // Limpiar el vector de texturas para evitar duplicados
        m_modelTextures2.clear();

        // Asignar textura Stormtrooper2 a cada submesh
        for (size_t i = 0; i < m_modelLoader2.m_meshes.size(); ++i) {
            Texture stormTex;
            HRESULT texResult = stormTex.init(m_device, "Textures/Stormtrooper2.png", PNG);

            if (FAILED(texResult)) {
                ERROR("Texture", "Stormtrooper2", "Failed to load texture for submesh.");
            }

            m_modelTextures2.push_back(stormTex);
        }

        AStorm = EngineUtilities::MakeShared<Actor>(m_device);
        if (!AStorm.isNull()) {
            AStorm->getComponent<Transform>()->setTransform(
                { -2.0f, 1.0f, 0.0f },
                { XM_PI / -2.0f, 0.0f, XM_PI },
                { 1.0f, 1.0f, 1.0f }
            );
            AStorm->setMesh(m_device, m_modelLoader2.m_meshes);
            AStorm->setTextures(m_modelTextures2);

            MESSAGE("Actor", "AStorm", (AStorm->getName() + " - Actor accessed successfully.").c_str());
        }
        else {
            ERROR("Actor", "AStorm", "Failed to create actor.");
        }

        // -------------------- Peely --------------------
        // Carga un modelo en formato .OBJ usando el cargador OBJ_Loader encapsulado en ModelLoader.
        // El modelo corresponde al personaje "Peely" (Banana.obj).
        m_modelLoader3.LoadOBJ_model("Models/Banana.obj");
        if (m_modelLoader3.m_meshes.empty()) {
            ERROR("Peely", "ModelLoader", "Banana.obj no contiene mallas.");
        }
        else {
            MESSAGE("Peely", "ModelLoader", ("Cantidad de mallas cargadas: " + std::to_string(m_modelLoader3.m_meshes.size())).c_str());
        }

        // Validar que sí se hayan cargado meshes
        MESSAGE("ModelLoader", "Chaos", ("Meshes loaded: " + std::to_string(m_modelLoader3.m_meshes.size())).c_str());

        // Limpiar el vector de texturas para evitar duplicados
        m_modelTextures3.clear();

        // Asignar textura Peely a cada submesh
        for (size_t i = 0; i < m_modelLoader3.m_meshes.size(); ++i) {
            Texture chaosTex;
            HRESULT texResult = chaosTex.init(m_device, "Textures/Peelybanana.png", PNG);

            if (FAILED(texResult)) {
                ERROR("Texture", "Peelybanana", "Failed to load texture for submesh.");
            }

            m_modelTextures3.push_back(chaosTex);
        }
        // Creación del Actor AChaos (representa a Peely en la escena)
        AChaos = EngineUtilities::MakeShared<Actor>(m_device);
        if (!AChaos.isNull()) {
            AChaos->getComponent<Transform>()->setTransform(
                { -8.0, -3.0f, 0.5f },      // Posición
                { XM_PI / -1.0f, 0.0f, XM_PI }, // Rotación (en radianes)
                { 0.05f, 0.05f, 0.05f }      // Escala (muy pequeña)
            );
            // Se asignan las mallas procesadas desde el .OBJ al actor
            AChaos->setMesh(m_device, m_modelLoader3.m_meshes);
            // Se asignan las texturas a cada submesh del actor
            AChaos->setTextures(m_modelTextures3);

            MESSAGE("Actor", "AChaos", (AChaos->getName() + " - Actor accessed successfully.").c_str());
        }
        else {
            ERROR("Actor", "AChaos", "Failed to create actor.");
        }

        return S_OK;  
    }  
    void
    BaseApp::update() {
        // Actualiza el UI
        m_UI.update();

        // Debug window con algún texto
        ImGui::Begin("Crayola");
        ImGui::Text("Venom Venom Venom");
        ImGui::End();

        // -------------------- LethalGuy --------------------
        if (!ALethal.isNull()) {
            // Mostrar y editar transform en el UI
            m_UI.TransformGUI(*ALethal->getComponent<Transform>());
            // Actualizar lógica interna
            ALethal->update(0, m_deviceContext);
        }

        // -------------------- Stormtrooper --------------------
        if (!AStorm.isNull()) {
            // Mostrar y editar transform en el UI
            m_UI.TransformGUI(*AStorm->getComponent<Transform>());
            // Actualizar lógica interna
            AStorm->update(0, m_deviceContext);
        }

        // -------------------- Peely --------------------
        if (!AChaos.isNull()) {
            // Mostrar y editar transform en el UI
            m_UI.TransformGUI(*AChaos->getComponent<Transform>());
            // Actualizar lógica interna
            AChaos->update(0, m_deviceContext);
        }

        // -------------------- Tiempo --------------------
        static float t = 0.0f;
        if (m_swapchain.m_driverType == D3D_DRIVER_TYPE_REFERENCE) {
            t += (float)XM_PI * 0.0125f;
        }
        else {
            static DWORD dwTimeStart = 0;
            DWORD dwTimeCur = GetTickCount();
            if (dwTimeStart == 0)
                dwTimeStart = dwTimeCur;
            t = (dwTimeCur - dwTimeStart) / 1000.0f;
        }

        // Mostrar inspector general (puedes agregar controles)
        m_UI.Inspector();

        // Actualizar posición de cámara
        inputActionMap(t);

        // -------------------- Transformaciones de objeto (comentadas por si las necesitas luego) --------------------
        /*
        m_modelMatrix = XMMatrixRotationY(t);
        m_vMeshColor = XMFLOAT4(
            (sinf(t * 1.0f) + 1.0f) * 0.5f,
            (cosf(t * 3.0f) + 1.0f) * 0.5f,
            (sinf(t * 5.0f) + 1.0f) * 0.5f,
            1.0f
        );

        XMMATRIX scaleMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);
        XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
        XMMATRIX translationMatrix = XMMatrixTranslation(position.x, position.y, position.z);

        m_modelMatrix = scaleMatrix * rotationMatrix * translationMatrix;

        cb.mWorld = XMMatrixTranspose(m_modelMatrix);
        cb.vMeshColor = m_vMeshColor;

        m_changesEveryFrame.update(m_deviceContext, 0, nullptr, &cb, 0, 0);
        */

        // -------------------- Matriz de proyección --------------------
        float FOV = XMConvertToRadians(90.0F);
        m_Projection = XMMatrixPerspectiveFovLH(FOV, m_window.m_width / (float)m_window.m_height, 0.01f, 10000.0f);

        cbChangesOnResize.mProjection = XMMatrixTranspose(m_Projection);
        m_changeOnResize.update(m_deviceContext, 0, nullptr, &cbChangesOnResize, 0, 0);

        // -------------------- Cámara --------------------
        updateCamera();
    }

    void
    BaseApp::render() {
        // Clear the back buffer
        float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red, green, blue, alpha

        // Set Viewport
        m_viewport.render(m_deviceContext);

        // Set Render Target View
        m_renderTargetView.render(m_deviceContext, m_depthStencilView, 1, ClearColor);

        // Set Depth Stencil View
        m_depthStencilView.render(m_deviceContext);

        // Render the cube
        // Set Buffers and Shaders for pipeline
        m_shaderProgram.render(m_deviceContext);
        /*m_vertexBuffer.render(m_deviceContext, 0, 1);
        m_indexBuffer.render(m_deviceContext, 0, 1, false, DXGI_FORMAT_R32_UINT);*/
        /*m_deviceContext.IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);*/


        // Render the models
        ALethal->render(m_deviceContext);
        AStorm->render(m_deviceContext);
        AChaos->render(m_deviceContext);


        // Set Constant Buffers and assign Shaders
        // g_deviceContext.m_deviceContext->VSSetShader(g_pVertexShader, NULL, 0);
        m_neverChange.render(m_deviceContext, 0, 1);
        m_changeOnResize.render(m_deviceContext, 1, 1);
       /* m_changesEveryFrame.render(m_deviceContext, 2, 1);*/

        /*m_changesEveryFrame.render(m_deviceContext, 2, 1, true);*/
        /*m_modelTexture.render(m_deviceContext, 0, 1);*/
        /*m_samplerState.render(m_deviceContext, 0, 1);
        m_deviceContext.PSSetSamplers(0, 1, &g_pSamplerLinear);*/

        // Draw
        /*m_deviceContext.DrawIndexed(36, 0, 0);*/

        // Render the UI
        m_UI.render();

        // Present our back buffer to our front buffer
        m_swapchain.present();
    }

    void
    BaseApp::destroy() {
        if (m_deviceContext.m_deviceContext) m_deviceContext.m_deviceContext->ClearState();

        if (g_pSamplerLinear) g_pSamplerLinear->Release();

        m_modelTexture.destroy();
        //m_samplerState.destroy();
        m_changeOnResize.destroy();
        m_changesEveryFrame.destroy();
        m_neverChange.destroy();
       /* m_indexBuffer.destroy();
        m_vertexBuffer.destroy();*/
        m_shaderProgram.destroy();
        m_depthStencil.destroy();
        m_depthStencilView.destroy();
        m_renderTargetView.destroy();
        m_swapchain.destroy();
        m_deviceContext.destroy();
        m_device.destroy();
        ALethal->destroy();
        m_UI.destroy();
    }

    int
    BaseApp::run(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPWSTR lpCmdLine,
        int nCmdShow,
        WNDPROC wndproc) {
        UNREFERENCED_PARAMETER(hPrevInstance);
        UNREFERENCED_PARAMETER(lpCmdLine);

        if (FAILED(m_window.init(hInstance, nCmdShow, wndproc)))
            return 0;

        if (FAILED(init())) {
            destroy();
            return 0;
        }

        // Main message loop
        MSG msg = { 0 };
        while (WM_QUIT != msg.message) {
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            else {
                update();
                render();
            }
        }

        destroy();

        return (int)msg.wParam;
    }

    void BaseApp::inputActionMap(float DeltaTime) {
        float Sensibility = 0.001f;
        float moveSpeedCamera = 0.01f;

        /*if (keys['W']) {
            position.y += Sensibility * DeltaTime;
        }
        if (keys['S']) {
            position.y -= Sensibility * DeltaTime;
        }
        if (keys['A']) {
            position.x -= Sensibility * DeltaTime;
        }
        if (keys['D']) {
            position.x += Sensibility * DeltaTime;
        }
        if (keys['Q']) {
            position.z -= Sensibility * DeltaTime;
        }
        if (keys['E']) {
            position.z += Sensibility * DeltaTime;
        }*/

        XMVECTOR pos = XMLoadFloat3(&m_camera.position);
        XMVECTOR forward = XMLoadFloat3(&m_camera.forward);
        XMVECTOR right = XMLoadFloat3(&m_camera.right);

        if (keys['W']) {
            pos += forward * moveSpeedCamera;
        }
        if (keys['S']) {
            pos -= forward * moveSpeedCamera;
        }
        if (keys['A']) {
            pos -= right * moveSpeedCamera;
        }
        if (keys['D']) {
            pos += right * moveSpeedCamera;
        }

        XMStoreFloat3(&m_camera.position, pos);
    }

    void
    BaseApp::updateCamera() {
        // Normalizar el vector de dirección
        XMVECTOR pos = XMLoadFloat3(&m_camera.position);
        XMVECTOR dir = XMLoadFloat3(&m_camera.forward);
        XMVECTOR up = XMLoadFloat3(&m_camera.up);

        // Calcular la matriz de vista
        m_View = XMMatrixLookAtLH(pos, pos + dir, up);

        cbNeverChanges.mView = XMMatrixTranspose(m_View);
        m_neverChange.update(m_deviceContext, 0, nullptr, &cbNeverChanges, 0, 0);
    }

    void
    BaseApp::rotateCamera(int mouseX, int mouseY) {
        float offsetX = (mouseX - lastX) * sensitivity;
        float offsetY = (mouseY - lastY) * sensitivity;
        lastX = mouseX;
        lastY = mouseY;

        m_camera.yaw += offsetX;
        m_camera.pitch += offsetY;

        //Limitar la inclinación de la cámara

        if (m_camera.pitch > 1.5f) m_camera.pitch = 1.5f;
        if (m_camera.pitch < -1.5f) m_camera.pitch = -1.5f;

        XMVECTOR forward = XMVectorSet(
            cosf(m_camera.yaw) * cosf(m_camera.pitch),
            sinf(m_camera.pitch),
            sinf(m_camera.yaw) * cosf(m_camera.pitch),
            0.0f
        );

        XMVECTOR right = XMVector3Cross(forward, XMLoadFloat3(&m_camera.up));

        XMStoreFloat3(&m_camera.forward, XMVector3Normalize(forward));
        XMStoreFloat3(&m_camera.right, XMVector3Normalize(right));
    }

    HRESULT
    BaseApp::resize(HWND hwwnd, LPARAM lparam) {
        if (m_swapchain.m_swapchain) {

            m_renderTargetView.destroy();
            m_depthStencil.destroy();
            m_depthStencilView.destroy();
            m_backBuffer.destroy();

            m_window.m_width = LOWORD(lparam);
            m_window.m_height = HIWORD(lparam);

            HRESULT hr = m_swapchain.m_swapchain->ResizeBuffers(0, m_window.m_width, m_window.m_height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
            if (FAILED(hr)) {
                ERROR("SwapChain", "Resize", "Failed to resize the SwapChain buffers");
                return hr;
            }

            hr = m_swapchain.m_swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&m_backBuffer.m_texture));
            if (FAILED(hr)) {
                ERROR("SwapChain", "Resize", "Failed to get new back buffer");
            }

            hr = m_renderTargetView.init(m_device, m_backBuffer, DXGI_FORMAT_R8G8B8A8_UNORM);
            if (FAILED(hr)) {
                ERROR("RenderTargetView", "Resize", "Failed to create new RenderTargetView");
                return hr;
            }

            hr = m_depthStencil.init(m_device, m_window.m_width, m_window.m_height, DXGI_FORMAT_D24_UNORM_S8_UINT, D3D11_BIND_DEPTH_STENCIL, 4, 0);
            if (FAILED(hr)) {
                ERROR("DepthStencil", "Resize", "Failed to create new DepthStencil");
                return hr;
            }

            hr = m_depthStencilView.init(m_device, m_depthStencil, DXGI_FORMAT_D24_UNORM_S8_UINT);
            if (FAILED(hr)) {
                ERROR("DepthStencilView", "Resize", "Failed to create new DepthStencilView");
                return hr;
            }

            hr = m_viewport.init(m_window);
            if (FAILED(hr)) {
                ERROR("Viewport", "Resize", "Failed to create new Viewport");
                return hr;
            }

            m_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, m_window.m_width / (float)m_window.m_height, 0.01f, 100.0f);
            cbChangesOnResize.mProjection = XMMatrixTranspose(m_Projection);
            m_changeOnResize.update(m_deviceContext, 0, nullptr, &cbChangesOnResize, 0, 0);
        }
    }
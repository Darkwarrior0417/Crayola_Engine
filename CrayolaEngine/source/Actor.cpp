#include "ECS/Actor.h"
#include "MeshComponent.h"
#include "Device.h"

/**
 * @brief Constructor del Actor.
 * Crea componentes Transform y Mesh por defecto, y configura buffers y sampler.
 */
Actor::Actor(Device& device) {
    auto transform = EngineUtilities::MakeShared<Transform>();
    addComponent(transform);

    auto mesh = EngineUtilities::MakeShared<MeshComponent>();
    addComponent(mesh);

    HRESULT hr;
    string classNameType = "Actor -> " + m_name;

    // Inicialización del buffer constante para cambios cada frame
    hr = m_modelBuffer.init(device, sizeof(CBChangesEveryFrame));
    if (FAILED(hr)) {
        ERROR("Actor", classNameType.c_str(), "Failed to create CBChangesEveryFrame buffer.");
    }

    // Inicialización del Sampler State
    hr = m_sampler.init(device);
    if (FAILED(hr)) {
        ERROR("Actor", classNameType.c_str(), "Failed to create SamplerState.");
    }
}

void 
Actor::update(float deltaTime, DeviceContext& deviceContext) {
    auto transform = getComponent<Transform>();
    if (!transform.isNull()) {
        transform->update(deltaTime);
        m_changeEveryFrame.mWorld = XMMatrixTranspose(transform->matrix);
    }
    else {
        m_changeEveryFrame.mWorld = XMMatrixIdentity();
    }

    // Color de la malla (puede personalizarse en el futuro)
    m_changeEveryFrame.vMeshColor = XMFLOAT4(0.7f, 0.7f, 0.7f, 1.0f);
    // Actualizar el constant buffer en la GPU
    m_modelBuffer.update(deviceContext, 0, nullptr, &m_changeEveryFrame, 0, 0);
}

void 
Actor::render(DeviceContext& deviceContext) {
    // Aplicar el Sampler State
    m_sampler.render(deviceContext, 0, 1);

    // Dibujar todas las mallas asociadas
    for (size_t i = 0; i < m_meshes.size(); ++i) {
        if (i < m_vertexBuffers.size() && i < m_indexBuffers.size()) {
            // Establecer vertex e index buffers    
            m_vertexBuffers[i].render(deviceContext, 0, 1);
            m_indexBuffers[i].render(deviceContext, 0, 1, false, DXGI_FORMAT_R32_UINT);

            // Establecer textura asociada (si existe)
            if (i < m_textures.size()) {
                m_textures[i].render(deviceContext, 0, 1);
            }

            // Establecer el Constant Buffer para el shader
            m_modelBuffer.render(deviceContext, 2, 1, true);
            // Configurar la topología de primitivas (triángulos)
            deviceContext.IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
            // Dibujar la malla
            deviceContext.DrawIndexed(m_meshes[i].m_numIndex, 0, 0);
        }
    }
}

void 
Actor::destroy() {
    for (auto& vb : m_vertexBuffers) {
        vb.destroy();
    }
    for (auto& ib : m_indexBuffers) {
        ib.destroy();
    }
    for (auto& tex : m_textures) {
        tex.destroy();
    }

    m_modelBuffer.destroy();
    m_sampler.destroy();
}

void 
Actor::setMesh(Device& device, const std::vector<MeshComponent>& meshes) {
    m_meshes = meshes;
    HRESULT hr;

    m_vertexBuffers.clear();
    m_indexBuffers.clear();

    for (const auto& mesh : m_meshes) {
        Buffer vertexBuffer;
        hr = vertexBuffer.init(device, mesh, D3D11_BIND_VERTEX_BUFFER);
        if (FAILED(hr)) {
            ERROR("Actor", "setMesh", "Failed to create VertexBuffer");
        }
        else {
            m_vertexBuffers.push_back(vertexBuffer);
        }

        Buffer indexBuffer;
        hr = indexBuffer.init(device, mesh, D3D11_BIND_INDEX_BUFFER);
        if (FAILED(hr)) {
            ERROR("Actor", "setMesh", "Failed to create IndexBuffer");
        }
        else {
            m_indexBuffers.push_back(indexBuffer);
        }
    }
}

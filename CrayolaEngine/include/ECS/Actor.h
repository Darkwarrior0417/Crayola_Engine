#pragma once
#include "Prerequisites.h"
#include "ECS/Entity.h"
#include "Buffer.h"
#include "Texture.h"
#include "SamplerState.h"
#include "Transform.h"



class Device;
class Component;

class
    Actor : Entity {
public:

    Actor() = default;
    Actor(Device& device);
    virtual ~Actor() = default;



    void
        update(float deltaTime, DeviceContext& deviceContext) override;


    void
        render(DeviceContext& deviceContext) override;

    void
        destroy();

    void
        setMesh(Device& device, std::vector<MeshComponent> meshes);

    void
        setTextures(std::vector<Texture> textures) {
        m_textures = textures;
    }

    std::string
        getName() {
        return m_name;
    }


    template<typename T>
    EngineUtilities::TSharedPointer<T>
        getComponent();

private:
    std::vector<MeshComponent> m_meshes;
    std::vector<Texture> m_textures;
    std::vector<Buffer> m_vertexBuffers;
    std::vector<Buffer> m_indexBuffers;

    CBChangesEveryFrame m_model;
    Buffer m_modelBuffer;
    SamplerState m_sampler;
    std::string m_name = "Actor";
};


template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
    for (auto& component : m_components) {
        EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
        if (specificComponent) {
            return specificComponent;
        }
    }
    return EngineUtilities::TSharedPointer<T>();
}
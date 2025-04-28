#pragma once
#include "Prerequisites.h"
#include "DeviceContext.h"
#include "ECS/Component.h"

/**
 * @brief Representa una malla 3D compuesta por vértices e índices.
 * Este componente se adjunta a un Actor dentro del sistema ECS.
 */
class MeshComponent : public Component {
public:

    /**
     * @brief Constructor que inicializa los contadores de vértices e índices en cero
     * y define el tipo de componente como MESH.
     */
    MeshComponent() : m_numVertex(0), m_numIndex(0), Component(ComponentType::MESH) {}

    /**
     * @brief Destructor por defecto.
     */
    virtual
    ~MeshComponent() = default;

    /**
     * @brief Actualiza la lógica del componente (no implementado para mallas).
     * @param deltaTime Tiempo transcurrido entre frames.
     */
    void
    update(float deltaTime) override {}

    /**
     * @brief Renderiza la malla (implementación vacía; la renderización real ocurre en otro nivel).
     * @param deviceContext Contexto de dispositivo utilizado para el renderizado.
     */
    void
    render(DeviceContext& deviceContext) override {}

public:
    std::string m_name;                      // Nombre de la malla (opcional para identificarla).
    std::vector<SimpleVertex> m_vertex;      // Lista de vértices del modelo.
    std::vector<unsigned int> m_index;       // Lista de índices para dibujar la malla.
    int m_numVertex;                         // Cantidad total de vértices.
    int m_numIndex;                          // Cantidad total de índices.
};
